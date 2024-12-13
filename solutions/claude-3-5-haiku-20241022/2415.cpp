#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAXN = 5001;
 
int main() {
    int n;
    cin >> n;
 
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    dp[0][0] = 1;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j - 1] * i) % MOD;
            dp[i][j] += (dp[i - 1][j] * (i - 1)) % MOD;
            dp[i][j] %= MOD;
        }
    }
 
    for (int k = 1; k <= n; k++) {
        cout << dp[n][k] << "\n";
    }
 
    return 0;
}