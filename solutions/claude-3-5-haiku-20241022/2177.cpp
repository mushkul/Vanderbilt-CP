#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

bool is_connected(vector<vector<int>>& adj, int n) {
    vector<bool> visited(n + 1, false);
    int start = -1;
    for (int i = 1; i <= n; i++) {
        if (!adj[i].empty()) {
            start = i;
            break;
        }
    }
    if (start == -1) return true;

    dfs(start, adj, visited);
    
    for (int i = 1; i <= n; i++) {
        if (!adj[i].empty() && !visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges(m);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i] = {a, b};
    }

    vector<vector<int>> directed_adj(n + 1);
    for (auto& e : edges) {
        int a = e.first, b = e.second;
        directed_adj[a].push_back(b);
        directed_adj[b].push_back(a);
    }

    if (!is_connected(directed_adj, n)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for (auto& e : edges) {
        cout << e.first << " " << e.second << "\n";
    }

    return 0;
}