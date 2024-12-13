#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
 
int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0; i<m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    vector<ll> dist(n+1,LLONG_MAX);
    vector<ll> ways(n+1,0);
    vector<ll> min_flights(n+1,LLONG_MAX);
    vector<ll> max_flights(n+1,0);
    
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    
    dist[1] = 0;
    ways[1] = 1;
    min_flights[1] = 0;
    max_flights[1] = 0;
    pq.push({0,1});
    
    while(!pq.empty()) {
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        
        if(d > dist[u]) continue;
        
        for(auto edge : adj[u]) {
            ll v = edge.first;
            ll c = edge.second;
            
            if(dist[v] > d + c) {
                dist[v] = d + c;
                ways[v] = ways[u];
                min_flights[v] = min_flights[u] + 1;
                max_flights[v] = max_flights[u] + 1;
                pq.push({dist[v], v});
            }
            else if(dist[v] == d + c) {
                ways[v] = (ways[v] + ways[u]) % mod;
                min_flights[v] = min(min_flights[v], min_flights[u] + 1);
                max_flights[v] = max(max_flights[v], max_flights[u] + 1);
            }
        }
    }
    
    cout << dist[n] << " " << ways[n] << " " << min_flights[n] << " " << max_flights[n];
    
    return 0;
}