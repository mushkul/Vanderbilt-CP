#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;

int n, q, timer;
int up[MAXN][LOG], depth[MAXN];

void dfs(int v, int parent, vector<vector<int>>& adj) {
    up[v][0] = parent;
    for (int j = 1; j < LOG; j++) {
        up[v][j] = up[up[v][j-1]][j-1];
    }
    
    for (int u : adj[v]) {
        if (u != parent) {
            depth[u] = depth[v] + 1;
            dfs(u, v, adj);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    int k = depth[a] - depth[b];
    for (int j = LOG - 1; j >= 0; j--) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }
    
    if (a == b) return a;
    
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    
    return up[a][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    
    for (int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }
    
    depth[1] = 0;
    dfs(1, 1, adj);
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    
    return 0;
}