#include <bits/stdc++.h>
using namespace std;
 
const int MAX_N = 2e5+5;
vector<int> adj[MAX_N];
vector<int> ans(MAX_N);
vector<vector<int>> up;
int timer;
vector<int> tin, tout;
int l;
 
void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; i++)
        up[v][i] = up[up[v][i-1]][i-1];
 
    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }
    tout[v] = ++timer;
}
 
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
 
int lca(int u, int v) {
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
 
void mark_path(int u, int v) {
    int w = lca(u, v);
    while(u != w) {
        ans[u]++;
        u = up[u][0];
    }
    while(v != w) {
        ans[v]++;
        v = up[v][0];
    }
    ans[w]++;
}
 
void preprocess(int root, int n) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n+1, vector<int>(l + 1));
    dfs(root, root);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    preprocess(1, n);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mark_path(a, b);
    }
    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}