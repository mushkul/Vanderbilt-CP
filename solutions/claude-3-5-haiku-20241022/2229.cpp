#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 505;

int dp[MAXN][MAXN];

int main() {
    int n, k;
    cin >> n >> k;
    
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            
            if (j >= 1) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
            }
            
            if (j >= i) {
                dp[i][j] = (dp[i][j] - dp[i-1][j-i]) % MOD;
                if (dp[i][j] < 0) dp[i][j] += MOD;
            }
        }
    }
    
    cout << dp[n][k] << endl;
    
    return 0;
}