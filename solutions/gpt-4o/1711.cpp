#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> path;
vector<int> visited;
int n, m;

bool dfs(int node) {
    if (node == n) return true;
    visited[node] = 1;
    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (!visited[next]) {
            if (dfs(next)) {
                path.push_back(next);
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    vector<vector<int>> paths;
    
    while (true) {
        visited.assign(n + 1, 0);
        path.clear();
        if (!dfs(1)) break;
        reverse(path.begin(), path.end());
        path.push_back(1);
        reverse(path.begin(), path.end());
        paths.push_back(path);
        
        for (int i = 0; i < path.size() - 1; i++) {
            int u = path[i], v = path[i + 1];
            adj[u].erase(find(adj[u].begin(), adj[u].end(), v));
        }
    }
    
    cout << paths.size() << "\n";
    for (const auto& path : paths) {
        cout << path.size() << "\n";
        for (int room : path) {
            cout << room << " ";
        }
        cout << "\n";
    }
    
    return 0;
}