#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll INF = 1e18;
 
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<ll,ll>>> adj(n+1);
    vector<vector<pair<ll,ll>>> rev(n+1);
    
    for(int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        rev[b].push_back({a,c}); 
    }
    
    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    
    while(!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto [v,w] : adj[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    ll minDist = dist[n];
    
    vector<ll> dist2(n+1, INF);
    dist2[n] = 0;
    pq.push({0,n});
    
    while(!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        
        if(d > dist2[u]) continue;
        
        for(auto [v,w] : rev[u]) {
            if(dist2[v] > dist2[u] + w) {
                dist2[v] = dist2[u] + w;
                pq.push({dist2[v], v});
            }
        }
    }
    
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        if(dist[i] + dist2[i] == minDist) {
            ans.push_back(i);
        }
    }
    
    cout << ans.size() << "\n";
    for(int x : ans) {
        cout << x << " ";
    }
    
    return 0;
}