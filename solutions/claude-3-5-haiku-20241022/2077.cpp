#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int disc[MAXN], low[MAXN], parent[MAXN];
bool articulation[MAXN];
int timer;

void dfs(int u) {
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (!disc[v]) {
            children++;
            parent[v] = u;
            dfs(v);
            
            low[u] = min(low[u], low[v]);
            
            if (parent[u] == 0 && children > 1)
                articulation[u] = true;
            
            if (parent[u] != 0 && low[v] >= disc[u])
                articulation[u] = true;
        }
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
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
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!disc[i]) {
            parent[i] = 0;
            dfs(i);
        }
    }
    
    vector<int> necessary;
    for (int i = 1; i <= n; i++) {
        if (articulation[i])
            necessary.push_back(i);
    }
    
    cout << necessary.size() << "\n";
    for (int city : necessary)
        cout << city << " ";
    
    return 0;
}