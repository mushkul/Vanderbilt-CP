#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    if (m < n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    vector<vector<int>> adj(n + 1), rev(n + 1);
    vector<int> indeg(n + 1, 0), outdeg(n + 1, 0);
    vector<pair<int, int>> edges;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.emplace_back(a, b);
    }

    vector<int> color(n + 1, 0);
    function<bool(int, int)> bfs = [&](int s, int dest) {
        queue<int> q;
        q.push(s);
        color[s] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (v == dest) continue;

                if (color[v] == 0) {
                    color[v] = 1;
                    q.push(v);
                }
            }
        }

        return color[dest] == 1;
    };
    
    if (!bfs(1, -1)) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    fill(color.begin(), color.end(), 0);

    int root = edges[0].first;
    for (auto& edge : edges) {
        int a = edge.first, b = edge.second;
        if (!bfs(a, b)) swap(a, b);
        outdeg[a]++;
        indeg[b]++;
        rev[a].push_back(b);
    }
    
    queue<int> q;
    vector<int> order;

    for (int i = 1; i <= n; ++i) {
        if (indeg[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : rev[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    
    if (order.size() < n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<vector<int>> dag(n + 1);
    for (auto& edge : edges) {
        int a = edge.first, b = edge.second;
        dag[a].push_back(b);
    }
    
    for (auto& edge : edges) {
        if (find(dag[edge.first].begin(), dag[edge.first].end(), edge.second) != dag[edge.first].end()) {
            cout << edge.first << " " << edge.second << endl;
        }
    }

    return 0;
}