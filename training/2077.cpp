#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100005];
int disc[100005], low[100005], parent[100005];
bool visited[100005];
set<int> necessary_cities;
int time_counter = 0;

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++time_counter;
    int children = 0;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            dfs(v);

            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1)
                necessary_cities.insert(u);

            if (parent[u] != -1 && low[v] >= disc[u])
                necessary_cities.insert(u);
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    fill(parent, parent + n + 1, -1);

    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }

    cout << necessary_cities.size() << "\n";
    for (auto city : necessary_cities) {
        cout << city << " ";
    }
    cout << "\n";

    return 0;
}