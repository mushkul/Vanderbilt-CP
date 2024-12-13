#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<ll> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + x[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= min(i, k); ++j) {
            for (int p = 0; p < i; ++p) {
                dp[i][j] = min(dp[i][j], dp[p][j - 1] + (prefixSum[i] - prefixSum[p]) * (prefixSum[i] - prefixSum[p]));
            }
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}