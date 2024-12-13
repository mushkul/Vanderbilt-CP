#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int INF = 1e9;

vector<pair<int,int>> graph[MAXN];
int n, m, k;

bool dijkstra(int start, int end, vector<int>& path, set<pair<int,int>>& used_edges) {
    vector<int> dist(n+1, INF);
    vector<int> prev(n+1, -1);
    dist[start] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto [v, weight] : graph[u]) {
            if (used_edges.count({u, v})) continue;
            
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    if (dist[end] == INF) return false;
    
    path.clear();
    int curr = end;
    while (curr != -1) {
        path.push_back(curr);
        curr = prev[curr];
    }
    reverse(path.begin(), path.end());
    
    for (int i = 0; i < path.size() - 1; i++) {
        used_edges.insert({path[i], path[i+1]});
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({b, 1});
    }
    
    set<pair<int,int>> used_edges;
    vector<vector<int>> routes;
    
    for (int day = 0; day < k; day++) {
        vector<int> path;
        if (!dijkstra(1, n, path, used_edges)) {
            cout << -1 << '\n';
            return 0;
        }
        routes.push_back(path);
    }
    
    int total_coins = used_edges.size();
    cout << total_coins << '\n';
    
    for (auto& route : routes) {
        cout << route.size() << '\n';
        for (int room : route) {
            cout << room << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}