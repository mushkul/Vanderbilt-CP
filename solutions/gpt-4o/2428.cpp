#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    unordered_map<int, int> count;
    int distinct = 0;
    int left = 0;
    long long result = 0;

    for (int right = 0; right < n; ++right) {
        if (count[x[right]] == 0) {
            ++distinct;
        }
        ++count[x[right]];

        while (distinct > k) {
            --count[x[left]];
            if (count[x[left]] == 0) {
                --distinct;
            }
            ++left;
        }

        result += (right - left + 1);
    }

    cout << result << endl;
    return 0;
}