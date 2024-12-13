#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> degree(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        degree[i] = adj[i].size();
    }

    queue<int> q;
    vector<bool> isLeaf(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            q.push(i);
            isLeaf[i] = true;
        }
    }

    vector<pair<int, int>> newEdges;
    while (q.size() > 1) {
        int u = q.front();
        q.pop();
        int v = q.front();
        q.pop();
        
        newEdges.push_back({u, v});
        
        for (int neighbor : adj[u]) {
            if (--degree[neighbor] == 1 && !isLeaf[neighbor]) {
                q.push(neighbor);
                isLeaf[neighbor] = true;
            }
        }
        
        for (int neighbor : adj[v]) {
            if (--degree[neighbor] == 1 && !isLeaf[neighbor]) {
                q.push(neighbor);
                isLeaf[neighbor] = true;
            }
        }
    }

    cout << newEdges.size() << "\n";
    for (const auto &edge : newEdges) {
        cout << edge.first << " " << edge.second << "\n";
    }
    
    return 0;
}