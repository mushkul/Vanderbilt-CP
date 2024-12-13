#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int INF = 1e9;

int n, m;
vector<vector<int>> graph(MAXN, vector<int>(MAXN, 0));
vector<int> parent(MAXN);

int bfs(int source, int sink) {
    fill(parent.begin(), parent.end(), -1);
    queue<pair<int, int>> q;
    q.push({source, INF});
    parent[source] = source;

    while (!q.empty()) {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        if (u == sink) return flow;

        for (int v = 1; v <= n; v++) {
            if (parent[v] == -1 && graph[u][v] > 0) {
                int new_flow = min(flow, graph[u][v]);
                parent[v] = u;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int max_flow() {
    int total_flow = 0;
    while (true) {
        int path_flow = bfs(1, n);
        if (path_flow == 0) break;

        total_flow += path_flow;

        int v = n;
        while (v != 1) {
            int u = parent[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
            v = u;
        }
    }
    return total_flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] += c;
    }

    cout << max_flow() << "\n";

    return 0;
}