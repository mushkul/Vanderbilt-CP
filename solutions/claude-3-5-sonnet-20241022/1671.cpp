#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,ll>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    vector<ll> dist(n+1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,1});
    
    while(!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto p : adj[u]) {
            int v = p.first;
            ll w = p.second;
            
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    
    return 0;
}