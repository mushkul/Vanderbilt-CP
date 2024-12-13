#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
int disc[MAXN], low[MAXN], parent[MAXN];
bool visited[MAXN];
vector<pair<int, int>> bridges;
int timer;

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = timer++;
    
    for (int v : graph[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
            
            low[u] = min(low[u], low[v]);
            
            if (low[v] > disc[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        }
        else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
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
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    timer = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    cout << bridges.size() << "\n";
    for (auto bridge : bridges) {
        cout << bridge.first << " " << bridge.second << "\n";
    }
    
    return 0;
}