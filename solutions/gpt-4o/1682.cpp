#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> s;
    s.push(node);
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                s.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj1(n + 1), adj2(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    dfs(1, adj1, visited);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "NO\n" << 1 << " " << i << "\n";
            return 0;
        }
    }

    fill(visited.begin(), visited.end(), false);
    dfs(1, adj2, visited);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cout << "NO\n" << i << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}