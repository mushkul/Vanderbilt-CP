#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> path;
vector<pair<int, int>> edges;
vector<bool> used_edge;

void hierholzer(int u) {
    for (int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        int edge_idx = -1;
        for (int j = 0; j < edges.size(); j++) {
            if ((edges[j].first == u && edges[j].second == v || 
                 edges[j].first == v && edges[j].second == u) && !used_edge[j]) {
                edge_idx = j;
                break;
            }
        }
        
        if (edge_idx != -1) {
            used_edge[edge_idx] = true;
            graph[u].erase(graph[u].begin() + i);
            graph[v].erase(remove(graph[v].begin(), graph[v].end(), u), graph[v].end());
            hierholzer(v);
            i--;
        }
    }
    path.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    graph.resize(n + 1);
    used_edge.resize(m, false);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges.push_back({a, b});
    }
    
    vector<int> deg(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        deg[i] = graph[i].size();
    }
    
    int odd_count = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] % 2 == 1) odd_count++;
    }
    
    if (odd_count > 2) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    hierholzer(1);
    
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << "\n";
    
    return 0;
}