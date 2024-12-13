#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    int to, rev;
    ll cap;
    Edge(int t, ll c, int r) : to(t), cap(c), rev(r) {}
};

vector<vector<Edge>> adj;
vector<bool> vis;

ll dfs(int u, int t, ll f) {
    if (u == t) return f;
    vis[u] = true;
    
    for (auto &e : adj[u]) {
        if (!vis[e.to] && e.cap > 0) {
            ll flow = dfs(e.to, t, min(f, e.cap));
            if (flow > 0) {
                e.cap -= flow;
                adj[e.to][e.rev].cap += flow;
                return flow;
            }
        }
    }
    return 0;
}

ll maxFlow(int n) {
    ll flow = 0;
    while (true) {
        vis.assign(n+1, false);
        ll newFlow = dfs(1, n, LLONG_MAX);
        if (newFlow == 0) break;
        flow += newFlow;
    }
    return flow;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    adj.resize(n+1);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(Edge(b, c, adj[b].size()));
        adj[b].push_back(Edge(a, 0, adj[a].size()-1));
    }
    
    cout << maxFlow(n) << "\n";
    
    return 0;
}