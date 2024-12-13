#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50001;
vector<int> adj[MAXN];
int dp[MAXN];
bool vis[MAXN];

int dfs(int u) {
    if (dp[u] != -1) return dp[u];
    vis[u] = true;
    dp[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dp[u] += dfs(v);
        } else if (dp[v] != -1) {
            dp[u] += dp[v];
        }
    }
    vis[u] = false;
    return dp[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    memset(dp, -1, sizeof(dp));
    
    for (int i = 1; i <= n; i++) {
        if (dp[i] == -1) {
            dfs(i);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    
    return 0;
}