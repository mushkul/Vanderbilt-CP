#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;

int n, m;
vector<int> graph[MAXN];
int parent[MAXN];
bool visited[MAXN];

bool bfs() {
    memset(visited, 0, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == n) return true;

        for (int v : graph[u]) {
            if (!visited[v]) {
                parent[v] = u;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return false;
}

vector<int> findPath() {
    vector<int> path;
    for (int v = n; v != -1; v = parent[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    vector<vector<int>> routes;
    while (bfs()) {
        vector<int> path = findPath();
        routes.push_back(path);

        for (int i = 0; i < path.size() - 1; i++) {
            graph[path[i]].erase(
                remove(graph[path[i]].begin(), graph[path[i]].end(), path[i+1]),
                graph[path[i]].end()
            );
        }
    }

    cout << routes.size() << '\n';
    for (auto &route : routes) {
        cout << route.size() << '\n';
        for (int x : route) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}