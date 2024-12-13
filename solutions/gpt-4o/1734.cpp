#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Query {
    int l, r, index;
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--; // Zero indexing
        queries[i].r--;
        queries[i].index = i;
    }

    int BLOCK = 450; // ~sqrt(2 * 10^5)
    sort(queries.begin(), queries.end(), [&](Query a, Query b) {
        if (a.l / BLOCK != b.l / BLOCK) {
            return a.l / BLOCK < b.l / BLOCK;
        }
        return (a.l / BLOCK & 1) ? (a.r < b.r) : (a.r > b.r);
    });

    vector<int> answer(q);
    map<int, int> frequency;
    int currL = 0, currR = -1, distinct_count = 0;

    for (const Query& query : queries) {
        while (currL > query.l) {
            currL--;
            frequency[arr[currL]]++;
            if (frequency[arr[currL]] == 1) {
                distinct_count++;
            }
        }
        while (currR < query.r) {
            currR++;
            frequency[arr[currR]]++;
            if (frequency[arr[currR]] == 1) {
                distinct_count++;
            }
        }
        while (currL < query.l) {
            if (frequency[arr[currL]] == 1) {
                distinct_count--;
            }
            frequency[arr[currL]]--;
            currL++;
        }
        while (currR > query.r) {
            if (frequency[arr[currR]] == 1) {
                distinct_count--;
            }
            frequency[arr[currR]]--;
            currR--;
        }
        answer[query.index] = distinct_count;
    }

    for (int i = 0; i < q; ++i) {
        cout << answer[i] << '\n';
    }

    return 0;
}