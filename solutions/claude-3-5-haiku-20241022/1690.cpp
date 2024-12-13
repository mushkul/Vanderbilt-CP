#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
    }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));
    dp[1][0] = 1;
    
    for (int mask = 1; mask < (1 << n); mask++) {
        if (!(mask & 1)) continue;
        
        for (int j = 1; j < n; j++) {
            if (!(mask & (1 << j))) continue;
            
            int prev_mask = mask ^ (1 << j);
            
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                
                if ((prev_mask & (1 << k)) && graph[k+1][j+1]) {
                    dp[mask][j] += dp[prev_mask][k];
                    dp[mask][j] %= MOD;
                }
            }
        }
    }
    
    cout << dp[(1 << n) - 1][n-1] << endl;
    
    return 0;
}