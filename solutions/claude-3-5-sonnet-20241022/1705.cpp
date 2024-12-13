#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool vis[MAXN];

bool dfs(int u, int dest, int forbidden) {
    if(u == forbidden) return false;
    if(u == dest) return true;
    vis[u] = true;
    
    for(int v : adj[u]) {
        if(!vis[v]) {
            if(dfs(v, dest, forbidden)) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, q;
    cin >> n >> m >> q;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    while(q--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        memset(vis, false, sizeof(vis));
        if(dfs(a, b, c)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}