#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> parent;
vector<int> rank;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x == y)
        return;
    
    if (rank[x] < rank[y])
        swap(x, y);
    
    parent[y] = x;
    if (rank[x] == rank[y])
        rank[x]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    vector<pair<int, int>> solution;
    for (auto& edge : edges) {
        int u = edge.first, v = edge.second;
        
        if (find(u) != find(v)) {
            solution.emplace_back(u, v);
            unite(u, v);
        } else {
            solution.emplace_back(v, u);
        }
    }
    
    for (auto& [u, v] : solution) {
        cout << u << " " << v << "\n";
    }
    
    return 0;
}