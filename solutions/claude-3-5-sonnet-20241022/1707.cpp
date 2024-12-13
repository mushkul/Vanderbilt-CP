#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int ans = INF;
    
    for(int i = 1; i <= n; i++) {
        vector<int> dist(n+1, INF);
        vector<int> parent(n+1, -1);
        queue<int> q;
        
        dist[i] = 0;
        q.push(i);
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            
            for(int u : adj[v]) {
                if(dist[u] == INF) {
                    dist[u] = dist[v] + 1;
                    parent[u] = v;
                    q.push(u);
                }
                else if(parent[v] != u) {
                    ans = min(ans, dist[v] + dist[u] + 1);
                }
            }
        }
    }
    
    cout << (ans == INF ? -1 : ans);
    
    return 0;
}