#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const ll INF = 1e17;
const int MAXN = 2505;
 
struct Edge {
    int a, b;
    ll w;
};
 
int n, m;
vector<Edge> edges;
ll dist[MAXN];
int parent[MAXN];
 
void solve() {
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edges.push_back({a,b,w});
    }
    
    fill(dist, dist+n+1, 0);
    fill(parent, parent+n+1, -1);
    
    int cycle_start = -1;
    
    for(int i=0; i<n; i++) {
        cycle_start = -1;
        for(auto e : edges) {
            if(dist[e.a] + e.w < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.w;
                parent[e.b] = e.a;
                if(i == n-1) {
                    cycle_start = e.b;
                }
            }
        }
    }
    
    if(cycle_start == -1) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    
    for(int i=0; i<n; i++) {
        cycle_start = parent[cycle_start];
    }
    
    vector<int> cycle;
    for(int v = cycle_start; ; v = parent[v]) {
        cycle.push_back(v);
        if(v == cycle_start && cycle.size() > 1) break;
    }
    
    reverse(cycle.begin(), cycle.end());
    for(int x : cycle) cout << x << " ";
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}