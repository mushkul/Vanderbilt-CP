#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;
vector<int> adj[maxN];
int dp[maxN], parent[maxN], vis[maxN];
int n, m;

int dfs(int u) {
    if(u == n) return dp[u] = 1;
    if(vis[u] == 1) return dp[u];
    if(vis[u] == 2) return dp[u] = -1e9;
    
    vis[u] = 2;
    int best = -1e9;
    for(int v : adj[u]) {
        int val = dfs(v);
        if(val + 1 > best) {
            best = val + 1;
            parent[u] = v;
        }
    }
    dp[u] = best;
    vis[u] = 1;
    return dp[u];
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    memset(vis, 0, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    
    int ans = dfs(1);
    
    if(ans <= 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    cout << ans << "\n";
    
    vector<int> path;
    int curr = 1;
    while(curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }
    
    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << " \n"[i==path.size()-1];
    }
    
    return 0;
}