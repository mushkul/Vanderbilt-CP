#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }
    
    vector<int> dist(n + 1, -INF), parent(n + 1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[u] + 1 > dist[v]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    
    if (dist[n] == -INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        int curr = n;
        while (curr != -1) {
            path.push_back(curr);
            curr = parent[curr];
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int city : path) {
            cout << city << " ";
        }
        cout << endl;
    }
    
    return 0;
}