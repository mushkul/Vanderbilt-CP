#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> disc, low, parent;
vector<bool> visited;
vector<pair<int, int>> bridges;
vector<vector<int>> adjList;
int timeCounter;

void dfs(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timeCounter;
    for (int v : adjList[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridges.push_back((u < v) ? make_pair(u+1, v+1) : make_pair(v+1, u+1));
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adjList.resize(n);
    disc.assign(n, -1);
    low.assign(n, -1);
    parent.assign(n, -1);
    visited.assign(n, false);
    timeCounter = 0;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    sort(bridges.begin(), bridges.end());
    cout << bridges.size() << endl;
    for (const auto& bridge : bridges) {
        cout << bridge.first << " " << bridge.second << endl;
    }

    return 0;
}