#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
vector<int> revGraph[MAXN];
bool visited[MAXN];
stack<int> order;

void dfs1(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    order.push(v);
}

void dfs2(int v, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for (int u : revGraph[v]) {
        if (!visited[u]) {
            dfs2(u, component);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        revGraph[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    memset(visited, false, sizeof(visited));
    vector<vector<int>> components;

    while (!order.empty()) {
        int v = order.top();
        order.pop();
        if (!visited[v]) {
            vector<int> component;
            dfs2(v, component);
            components.push_back(component);
        }
    }

    vector<pair<int, int>> newFlights;
    for (int i = 1; i < components.size(); i++) {
        newFlights.push_back({components[i-1][0], components[i][0]});
    }

    cout << newFlights.size() << '\n';
    for (auto& flight : newFlights) {
        cout << flight.first << ' ' << flight.second << '\n';
    }

    return 0;
}