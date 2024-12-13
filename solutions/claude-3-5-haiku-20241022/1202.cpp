#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
    }
    
    vector<ll> dist(n+1, LLONG_MAX);
    vector<int> paths(n+1, 0);
    vector<int> minFlights(n+1, INT_MAX);
    vector<int> maxFlights(n+1, 0);
    dist[1] = 0;
    paths[1] = 1;
    minFlights[1] = 0;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                paths[v] = paths[u];
                minFlights[v] = minFlights[u] + 1;
                maxFlights[v] = maxFlights[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[v] == d + w) {
                paths[v] = (paths[v] + paths[u]) % MOD;
                minFlights[v] = min(minFlights[v], minFlights[u] + 1);
                maxFlights[v] = max(maxFlights[v], maxFlights[u] + 1);
            }
        }
    }
    
    cout << dist[n] << " " << paths[n] << " " << minFlights[n] << " " << maxFlights[n];
    
    return 0;
}