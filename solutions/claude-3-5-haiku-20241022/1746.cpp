#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(m + 1, 0));

    // Initialize first row
    if (arr[0] == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    } else {
        dp[0][arr[0]] = 1;
    }

    // Dynamic programming
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
        } else {
            int j = arr[i];
            dp[i][j] = dp[i-1][j];
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            if (j < m) dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
        }
    }

    ll result = 0;
    for (int j = 1; j <= m; j++) {
        result = (result + dp[n-1][j]) % MOD;
    }

    cout << result << endl;

    return 0;
}