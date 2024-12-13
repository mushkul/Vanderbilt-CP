#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const ll INF = LLONG_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1), rev_adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        rev_adj[b].emplace_back(a, c);
    }

    auto dijkstra = [](vector<vector<pair<int, ll>>>& graph, int start) {
        vector<ll> dist(graph.size(), INF);
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        dist[start] = 0;
        pq.emplace(0, start);
        while (!pq.empty()) {
            auto[d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto&[v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        return dist;
    };

    vector<ll> dist_from_start = dijkstra(adj, 1);
    vector<ll> dist_to_end = dijkstra(rev_adj, n);

    ll result = dist_from_start[n];
    for (int u = 1; u <= n; ++u) {
        for (auto[v, c] : adj[u]) {
            if (dist_from_start[u] != INF && dist_to_end[v] != INF) {
                result = min(result, dist_from_start[u] + dist_to_end[v] + c / 2);
            }
        }
    }

    cout << result << '\n';

    return 0;
}