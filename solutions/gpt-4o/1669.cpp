#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
stack<int> cycle;

bool dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (v != parent[u]) {
            // Cycle found
            cycle.push(v);
            while (u != v) {
                cycle.push(u);
                u = parent[u];
            }
            cycle.push(v); // push the start of the cycle again
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    parent.resize(n + 1, -1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool found = false;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && dfs(i)) {
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> result;
        int first = cycle.top();
        cycle.pop();
        while (!cycle.empty()) {
            result.push_back(cycle.top());
            cycle.pop();
        }
        cout << result.size() << endl;
        for (int city : result) {
            cout << city << ' ';
        }
        cout << endl;
    }

    return 0;
}