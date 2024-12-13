#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n+1, vector<bool>(n+1, false));
    
    for(int i = 0; i < m; i++) {
        int y, x;
        cin >> y >> x;
        grid[y][x] = true;
    }
    
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    dp[1][1] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1 && j == 1) continue;
            if(grid[i][j]) continue;
            
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    
    cout << dp[n][n];
    
    return 0;
}