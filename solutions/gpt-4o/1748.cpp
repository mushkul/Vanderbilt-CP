#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    map<int, int> subseq_counts;
    long long total = 0;

    for (int i = 0; i < n; ++i) {
        long long count = 1;
        auto it = subseq_counts.lower_bound(arr[i]);
        for (auto j = subseq_counts.begin(); j != it; ++j) {
            count = (count + j->second) % MOD;
        }
        subseq_counts[arr[i]] = (subseq_counts[arr[i]] + count) % MOD;
        total = (total + count) % MOD;
    }

    cout << total << endl;
    return 0;
}