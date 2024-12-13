#include <bits/stdc++.h>
using namespace std;

const int maxN = 100001;
vector<int> adj[maxN];
vector<bool> visited;
vector<int> order;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    order.push_back(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int,int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a,b});
    }
    
    visited.assign(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    reverse(order.begin(), order.end());
    vector<int> pos(n+1);
    for (int i = 0; i < n; i++) {
        pos[order[i]] = i;
    }
    
    for (auto e : edges) {
        if (pos[e.first] < pos[e.second]) {
            cout << e.first << " " << e.second << "\n";
        } else {
            cout << e.second << " " << e.first << "\n";
        }
    }
    
    return 0;
}