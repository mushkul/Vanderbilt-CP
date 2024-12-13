#include <bits/stdc++.h>
using namespace std;
 
const int INF = 1e9;
 
struct Edge {
    int to, rev;
    int flow, cap;
};
 
int n, m, k;
vector<vector<Edge>> adj;
vector<vector<int>> paths;
vector<bool> vis;
 
void add_edge(int u, int v) {
    Edge e1 = {v, (int)adj[v].size(), 0, 1};
    Edge e2 = {u, (int)adj[u].size(), 0, 0}; 
    adj[u].push_back(e1);
    adj[v].push_back(e2);
}
 
bool bfs(vector<int>& level, vector<int>& ptr) {
    fill(level.begin(), level.end(), -1);
    level[1] = 0;
    queue<int> q;
    q.push(1);
 
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& e : adj[v]) {
            if (e.flow < e.cap && level[e.to] == -1) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
    return level[n] != -1;
}
 
int dfs(int v, int flow, vector<int>& level, vector<int>& ptr) {
    if (v == n || !flow)
        return flow;
 
    for (int& i = ptr[v]; i < adj[v].size(); i++) {
        Edge& e = adj[v][i];
        if (level[e.to] != level[v] + 1 || e.flow >= e.cap)
            continue;
        
        int pushed = dfs(e.to, min(flow, e.cap - e.flow), level, ptr);
        if (pushed) {
            e.flow += pushed;
            adj[e.to][e.rev].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
 
int max_flow() {
    int flow = 0;
    vector<int> level(n + 1);
    vector<int> ptr(n + 1);
    
    while (bfs(level, ptr)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int pushed = dfs(1, INF, level, ptr))
            flow += pushed;
    }
    return flow;
}
 
void find_path() {
    vector<int> path;
    int cur = 1;
    path.push_back(1);
    vis[1] = true;
    
    while (cur != n) {
        for (auto& e : adj[cur]) {
            if (!vis[e.to] && e.flow > 0) {
                e.flow--;
                path.push_back(e.to);
                vis[e.to] = true;
                cur = e.to;
                break;
            }
        }
    }
    
    paths.push_back(path);
}
 
int main() {
    cin >> n >> m >> k;
    adj.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
    }
    
    int flow = max_flow();
    if (flow < k) {
        cout << -1;
        return 0;
    }
    
    int total = 0;
    for (int i = 0; i < k; i++) {
        vis.assign(n + 1, false);
        find_path();
        total += paths.back().size() - 1;
    }
    
    cout << total << "\n";
    for (auto& path : paths) {
        cout << path.size() - 1 << "\n";
        for (int v : path)
            cout << v << " ";
        cout << "\n";
    }
    
    return 0;
}