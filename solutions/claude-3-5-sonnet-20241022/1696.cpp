#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
vector<int> adj[MAXN];
int match[MAXN];
bool vis[MAXN];
vector<pair<int,int>> pairs;

bool dfs(int v) {
    for(int u : adj[v]) {
        if(vis[u]) continue;
        vis[u] = true;
        
        if(match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    memset(match, -1, sizeof(match));
    int cnt = 0;
    
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if(dfs(i)) cnt++;
    }
    
    cout << cnt << endl;
    
    for(int i = 1; i <= m; i++) {
        if(match[i] != -1) {
            cout << match[i] << " " << i << endl;
        }
    }
    
    return 0;
}