#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void dijkstra(int start, vector<vector<pair<int,ll>>>& graph, vector<ll>& dist) {
    dist.assign(graph.size(), INF);
    dist[start] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,ll>>> graph(n), graphReverse(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].push_back({b-1, c});
        graphReverse[b-1].push_back({a-1, c});
    }
    
    vector<ll> distFromStart(n), distToEnd(n);
    
    dijkstra(0, graph, distFromStart);
    dijkstra(n-1, graphReverse, distToEnd);
    
    ll minCost = INF;
    
    for (int u = 0; u < n; u++) {
        for (auto [v, w] : graph[u]) {
            ll cost = distFromStart[u] + (w/2) + distToEnd[v];
            minCost = min(minCost, cost);
        }
    }
    
    cout << minCost << '\n';
    
    return 0;
}