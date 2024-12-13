#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 1;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> trap(n+1, vector<bool>(n+1, false));
    
    for (int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;
        trap[y][x] = true;
    }
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    if (!trap[1][1]) {
        dp[1][1] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            
            if (!trap[i][j]) {
                if (i > 1 && !trap[i-1][j]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                }
                
                if (j > 1 && !trap[i][j-1]) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % MOD;
                }
            }
        }
    }
    
    cout << dp[n][n] << endl;
    
    return 0;
}