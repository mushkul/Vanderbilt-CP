#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(const vector<vector<int>>& adj, int start, int goal, int forbidden) {
    if (start == forbidden || goal == forbidden) return false;
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (node == goal) return true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor] && neighbor != forbidden) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < q; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << (bfs(adj, a, b, c) ? "YES" : "NO") << "\n";
    }

    return 0;
}