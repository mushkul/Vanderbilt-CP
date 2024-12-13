#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> disc, low;
vector<pair<int, int>> bridges;
vector<bool> visited;
int timeCounter;

void dfs(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = timeCounter++;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridges.push_back({min(u, v), max(u, v)});
            }
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    disc.resize(n + 1);
    low.resize(n + 1);
    visited.assign(n + 1, false);
    timeCounter = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    cout << bridges.size() << "\n";
    for (auto p : bridges) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}