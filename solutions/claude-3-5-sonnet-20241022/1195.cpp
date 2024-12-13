#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<ll,ll>>> adj(n+1);
    
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    vector<vector<ll>> dist(n+1, vector<ll>(2,1e18));
    
    priority_queue<tuple<ll,ll,ll>, vector<tuple<ll,ll,ll>>, greater<>> pq;
    pq.push({0,1,0}); // distance, node, discount used
    dist[1][0] = 0;
    
    while(!pq.empty()) {
        auto [d,u,used] = pq.top();
        pq.pop();
        
        if(d > dist[u][used]) continue;
        
        for(auto [v,w] : adj[u]) {
            if(!used) {
                if(dist[v][1] > d + w/2) {
                    dist[v][1] = d + w/2;
                    pq.push({dist[v][1], v, 1});
                }
            }
            
            if(dist[v][used] > d + w) {
                dist[v][used] = d + w;
                pq.push({dist[v][used], v, used});
            }
        }
    }
    
    cout << min(dist[n][0], dist[n][1]);
    return 0;
}