#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXN = 2500 + 5;
const ll INF = 1e18;

vector<pair<int, int>> graph[MAXN];
ll dist[MAXN];
bool reachable_from_start[MAXN];
bool reachable_to_end[MAXN];

void dfs_start(int node) {
    reachable_from_start[node] = true;
    for (auto [next, _] : graph[node]) {
        if (!reachable_from_start[next])
            dfs_start(next);
    }
}

void dfs_end(int node, vector<pair<int, int>> reversed_graph[]) {
    reachable_to_end[node] = true;
    for (auto [next, _] : reversed_graph[node]) {
        if (!reachable_to_end[next])
            dfs_end(next, reversed_graph);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> reversed_graph[MAXN];
    vector<tuple<int, int, int>> edges;
    
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        graph[a].push_back({b, x});
        reversed_graph[b].push_back({a, x});
        edges.push_back({a, b, x});
    }
    
    dfs_start(1);
    dfs_end(n, reversed_graph);
    
    for (int i = 1; i <= n; i++) {
        dist[i] = -INF;
    }
    dist[1] = 0;
    
    for (int i = 1; i <= n; i++) {
        for (auto [a, b, x] : edges) {
            if (dist[a] != -INF && reachable_from_start[a] && reachable_to_end[b]) {
                dist[b] = max(dist[b], dist[a] + x);
            }
        }
    }
    
    for (auto [a, b, x] : edges) {
        if (dist[a] != -INF && reachable_from_start[a] && reachable_to_end[b]) {
            if (dist[b] < dist[a] + x) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    
    cout << dist[n] << "\n";
    return 0;
}