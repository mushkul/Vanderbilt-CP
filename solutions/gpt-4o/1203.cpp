#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <set>
using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);
    vector<vector<pair<int, long long>>> rev_adj(n + 1);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        rev_adj[b].push_back({a, c});
    }

    auto dijkstra = [&](int src, vector<vector<pair<int, long long>>> &graph) {
        vector<long long> dist(n + 1, INF);
        dist[src] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u]) continue;

            for (auto &[v, len] : graph[u]) {
                if (dist[v] > dist[u] + len) {
                    dist[v] = dist[u] + len;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    };

    vector<long long> dist_from_start = dijkstra(1, adj);
    vector<long long> dist_to_end = dijkstra(n, rev_adj);

    long long min_cost = dist_from_start[n];
    set<int> certainly_on_route;

    for (int i = 1; i <= n; ++i) {
        if (dist_from_start[i] + dist_to_end[i] == min_cost) {
            certainly_on_route.insert(i);
        }
    }

    cout << certainly_on_route.size() << "\n";
    for (int city : certainly_on_route) {
        cout << city << " ";
    }
    cout << "\n";
    
    return 0;
}