#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<int> adj[MAX_N], rev_adj[MAX_N];
bool vis[MAX_N], vis2[MAX_N];

void dfs(int u, vector<int> adj[], bool vis[]) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) {
            dfs(v, adj, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    
    dfs(1, adj, vis);
    dfs(1, rev_adj, vis2);
    
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            cout << "NO\n";
            cout << "1 " << i;
            return 0;
        }
        if(!vis2[i]) {
            cout << "NO\n";
            cout << i << " 1";
            return 0;
        }
    }
    
    cout << "YES";
    return 0;
}