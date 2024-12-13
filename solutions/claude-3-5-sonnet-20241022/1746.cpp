#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    
    vector<vector<long long>> dp(n, vector<long long>(m+1, 0));
    
    if(x[0] == 0) {
        for(int i = 1; i <= m; i++) dp[0][i] = 1;
    } else {
        dp[0][x[0]] = 1;
    }
    
    for(int i = 1; i < n; i++) {
        if(x[i] == 0) {
            for(int j = 1; j <= m; j++) {
                for(int k : {j-1, j, j+1}) {
                    if(k >= 1 && k <= m) {
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                    }
                }
            }
        } else {
            for(int k : {x[i]-1, x[i], x[i]+1}) {
                if(k >= 1 && k <= m) {
                    dp[i][x[i]] = (dp[i][x[i]] + dp[i-1][k]) % MOD;
                }
            }
        }
    }
    
    long long ans = 0;
    for(int i = 1; i <= m; i++) {
        ans = (ans + dp[n-1][i]) % MOD;
    }
    
    cout << ans << "\n";
    return 0;
}