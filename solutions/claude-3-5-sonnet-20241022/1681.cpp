#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    vector<int> indeg(n+1);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    
    vector<ll> dp(n+1);
    dp[1] = 1;
    queue<int> q;
    
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }
    
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        
        for(int u : adj[v]) {
            dp[u] = (dp[u] + dp[v]) % MOD;
            indeg[u]--;
            if(indeg[u] == 0) {
                q.push(u);
            }
        }
    }
    
    cout << dp[n];
    return 0;
}