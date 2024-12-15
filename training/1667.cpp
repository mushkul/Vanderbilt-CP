#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> parent(n + 1, -1);
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (parent[neighbor] == -1) {
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    
    if (parent[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for (int v = n; v != 0; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}