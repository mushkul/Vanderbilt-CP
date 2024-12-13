#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dp(n + 1, vector<int>(1 << n, 0));
    dp[0][0] = 1;
    
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (int state = 0; state < (1 << n); state++) {
                if (dp[j][state] == 0) continue;
                
                if (state & (1 << i)) continue;
                
                int newState = state | (1 << i);
                
                if (i + 1 < n && !(state & (1 << (i + 1)))) {
                    int tempState = newState | (1 << (i + 1));
                    dp[j + (i + 1 == n - 1)][tempState] = (dp[j + (i + 1 == n - 1)][tempState] + dp[j][state]) % MOD;
                }
                
                if (j + 1 < m) {
                    dp[j + 1][newState] = (dp[j + 1][newState] + dp[j][state]) % MOD;
                }
            }
        }
    }
    
    int result = dp[m][0];
    cout << result << endl;
    
    return 0;
}