#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, capacity, cost;
};

int minCost(int n, int m, int k, vector<Edge>& edges) {
    vector<vector<int>> graph(n + 1);
    vector<vector<int>> capacity(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));

    for (auto& e : edges) {
        graph[e.from].push_back(e.to);
        graph[e.to].push_back(e.from);
        capacity[e.from][e.to] = e.capacity;
        cost[e.from][e.to] = e.cost;
    }

    int totalCost = 0;
    int flow = 0;

    while (flow < k) {
        vector<int> dist(n + 1, INF);
        vector<int> parent(n + 1, -1);
        vector<bool> inQueue(n + 1, false);
        queue<int> q;

        dist[1] = 0;
        q.push(1);
        inQueue[1] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            inQueue[u] = false;

            for (int v : graph[u]) {
                if (capacity[u][v] > 0 && dist[v] > dist[u] + cost[u][v]) {
                    dist[v] = dist[u] + cost[u][v];
                    parent[v] = u;
                    if (!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = true;
                    }
                }
            }
        }

        if (dist[n] == INF) return -1;

        int bottleneck = k - flow;
        for (int v = n; v != 1; v = parent[v]) {
            int u = parent[v];
            bottleneck = min(bottleneck, capacity[u][v]);
        }

        for (int v = n; v != 1; v = parent[v]) {
            int u = parent[v];
            capacity[u][v] -= bottleneck;
            capacity[v][u] += bottleneck;
            totalCost += bottleneck * cost[u][v];
        }

        flow += bottleneck;
    }

    return totalCost;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, r, c;
        cin >> a >> b >> r >> c;
        edges.push_back({a, b, r, c});
    }

    int result = minCost(n, m, k, edges);
    cout << result << endl;

    return 0;
}