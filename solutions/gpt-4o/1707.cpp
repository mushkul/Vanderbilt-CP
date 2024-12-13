#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int answer = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        vector<int> dist(n + 1, INT_MAX);
        vector<int> parent(n + 1, -1);
        queue<int> q;
        q.push(i);
        dist[i] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == INT_MAX) {
                    dist[neighbor] = dist[node] + 1;
                    parent[neighbor] = node;
                    q.push(neighbor);
                } else if (parent[node] != neighbor) {
                    answer = min(answer, dist[node] + dist[neighbor] + 1);
                }
            }
        }
    }
    
    if (answer == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << answer << endl;
    }
    
    return 0;
}