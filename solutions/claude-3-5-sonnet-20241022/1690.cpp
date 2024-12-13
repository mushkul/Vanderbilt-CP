#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; 
        adj[a].push_back(b);
    }
    
    vector<vector<ll>> dp(1<<n, vector<ll>(n+1, 0));
    dp[1][1] = 1;
    
    for(int mask = 0; mask < (1<<n); mask++) {
        for(int cur = 1; cur <= n; cur++) {
            if(!(mask & (1<<(cur-1)))) continue;
            
            for(int next : adj[cur]) {
                if(mask & (1<<(next-1))) continue;
                dp[mask|(1<<(next-1))][next] += dp[mask][cur];
                dp[mask|(1<<(next-1))][next] %= MOD;
            }
        }
    }
    
    cout << dp[(1<<n)-1][n] << endl;
    return 0;
}