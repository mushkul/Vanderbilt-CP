#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + x[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }

    vector<vector<int>> knuth(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        knuth[i][i] = i;
    }

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            int j = i + len - 1;
            for (int k = knuth[i][j - 1]; k <= knuth[i + 1][j] && k < j; ++k) {
                long long cost = dp[i][k] + dp[k + 1][j] + prefixSum[j + 1] - prefixSum[i];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    knuth[i][j] = k;
                }
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}