#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, capacity, cost, flow;
    int rev;
    Edge(int to, int capacity, int cost, int rev) : 
        to(to), capacity(capacity), cost(cost), flow(0), rev(rev) {}
};

vector<vector<Edge>> adj;
vector<int> dist, parent, parent_edge;
vector<bool> inqueue;

bool spfa(int source, int sink) {
    dist.assign(adj.size(), INF);
    parent.assign(adj.size(), -1); 
    parent_edge.assign(adj.size(), -1);
    inqueue.assign(adj.size(), false);
    
    queue<int> q;
    dist[source] = 0;
    q.push(source);
    inqueue[source] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inqueue[u] = false;
        
        for (int i = 0; i < adj[u].size(); i++) {
            Edge &e = adj[u][i];
            int v = e.to;
            
            if (e.capacity > e.flow && dist[v] > dist[u] + e.cost) {
                dist[v] = dist[u] + e.cost;
                parent[v] = u;
                parent_edge[v] = i;
                if (!inqueue[v]) {
                    q.push(v);
                    inqueue[v] = true;
                }
            }
        }
    }
    
    return dist[sink] != INF;
}

int min_cost_flow(int source, int sink, int k) {
    int cost = 0;
    int flow = 0;
    
    while (flow < k && spfa(source, sink)) {
        int min_flow = k - flow;
        int cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            int edge_idx = parent_edge[cur];
            min_flow = min(min_flow, adj[prev][edge_idx].capacity - adj[prev][edge_idx].flow);
            cur = prev;
        }
        
        flow += min_flow;
        cost += min_flow * dist[sink];
        cur = sink;
        
        while (cur != source) {
            int prev = parent[cur];
            int edge_idx = parent_edge[cur];
            Edge &e = adj[prev][edge_idx];
            Edge &rev_e = adj[cur][e.rev];
            
            e.flow += min_flow;
            rev_e.flow -= min_flow;
            cur = prev;
        }
    }
    
    if (flow < k) return -1;
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    adj.resize(n);
    
    for (int i = 0; i < m; i++) {
        int a, b, r, c;
        cin >> a >> b >> r >> c;
        a--; b--;
        adj[a].push_back(Edge(b, r, c, adj[b].size()));
        adj[b].push_back(Edge(a, 0, -c, adj[a].size()-1));
    }
    
    cout << min_cost_flow(0, n-1, k) << "\n";
    
    return 0;
}