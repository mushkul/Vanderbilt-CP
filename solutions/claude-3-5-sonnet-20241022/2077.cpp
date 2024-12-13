#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;
vector<int> adj[maxN];
vector<int> ans;
int timer = 0;
int tin[maxN], low[maxN];
bool visited[maxN];

void dfs(int v, int p) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    bool isAP = false;
    
    for(int u : adj[v]) {
        if(u == p) continue;
        if(visited[u]) {
            low[v] = min(low[v], tin[u]);
        } else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if(low[u] >= tin[v] && p != -1)
                isAP = true;
            children++;
        }
    }
    
    if(p == -1 && children > 1)
        isAP = true;
        
    if(isAP)
        ans.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i])
            dfs(i, -1);
    }
    
    cout << ans.size() << "\n";
    for(int x : ans)
        cout << x << " ";
    cout << "\n";
    
    return 0;
}