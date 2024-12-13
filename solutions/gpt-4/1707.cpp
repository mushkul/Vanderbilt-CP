#include<bits/stdc++.h>
using namespace std;

#define INF (1LL<<60)
#define fi first
#define se second

typedef pair<int, int> ii;

int V, E, ans = INF;
vector<int> dist;
vector<bool> visited;
vector<vector<ii>> adj;

bool bfs(int start) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        visited[u] = true;
        for (auto& [v, w] : adj[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + w;
                q.push(v);
            } else if (dist[u] + w < dist[v]) {
                ans = min(ans, dist[u] + w - dist[v] + 1);
            }
        }
    }
    return ans != INF;
}

int main() {
    cin >> V >> E;
    dist.assign(V, INF);
    visited.assign(V, false);
    adj.resize(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, 1});
        adj[v].push_back({u, 1});
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (bfs(i)) break;
        }
    }
    
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}