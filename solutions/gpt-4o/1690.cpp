#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
    }
    
    vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
    dp[1][0] = 1;
    
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (mask & (1 << u)) {
                for (int v : graph[u]) {
                    if (!(mask & (1 << v))) {
                        dp[mask | (1 << v)][v] = (dp[mask | (1 << v)][v] + dp[mask][u]) % MOD;
                    }
                }
            }
        }
    }
    
    cout << dp[(1 << n) - 1][n - 1] << endl;
    return 0;
}