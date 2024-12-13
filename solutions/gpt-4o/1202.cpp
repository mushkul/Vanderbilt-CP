#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    
    vector<long long> dist(n + 1, INF);
    vector<int> minFlights(n + 1, INT_MAX);
    vector<int> maxFlights(n + 1, 0);
    vector<long long> countRoutes(n + 1, 0);
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[1] = 0;
    countRoutes[1] = 1;
    minFlights[1] = 0;
    
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [curDist, u] = pq.top();
        pq.pop();
        
        if (curDist > dist[u]) continue;
        
        for (auto &[v, weight] : adj[u]) {
            if (curDist + weight < dist[v]) {
                dist[v] = curDist + weight;
                countRoutes[v] = countRoutes[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({dist[v], v});
            } else if (curDist + weight == dist[v]) {
                countRoutes[v] = (countRoutes[v] + countRoutes[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }
    
    cout << dist[n] << " " << countRoutes[n] << " " << minFlights[n] << " " << maxFlights[n] << endl;
    
    return 0;
}