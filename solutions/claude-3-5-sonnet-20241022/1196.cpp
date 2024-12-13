#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<pair<ll,ll>>> adj(n+1);
    for(int i=0; i<m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    
    vector<ll> ans;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    vector<int> times(n+1, 0);
    
    pq.push({0,1});
    
    while(!pq.empty() && ans.size() < k) {
        ll dist = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        
        if(node == n) {
            ans.push_back(dist);
        }
        
        if(times[node] < k) {
            times[node]++;
            for(auto next : adj[node]) {
                ll nn = next.first;
                ll w = next.second;
                pq.push({dist + w, nn});
            }
        }
    }
    
    for(ll x : ans) cout << x << " ";
    
    return 0;
}