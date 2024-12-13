#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+5;
const int MAXLOG = 20;

vector<int> adj[MAXN];
int depth[MAXN];
int up[MAXN][MAXLOG];

void dfs(int v, int p) {
    up[v][0] = p;
    for(int i = 1; i < MAXLOG; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(int u : adj[v]) {
        if(u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for(int i = 0; i < MAXLOG; i++) {
        if((diff >> i) & 1) {
            u = up[u][i];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i = MAXLOG-1; i >= 0; i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int distance(int u, int v) {
    int l = lca(u, v);
    return depth[u] + depth[v] - 2*depth[l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    depth[1] = 0;
    dfs(1, 1);
    
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << distance(a, b) << "\n";
    }
    
    return 0;
}