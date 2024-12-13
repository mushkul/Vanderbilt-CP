#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n+1);
    visited.resize(n+1);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> components;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            components.push_back(i);
            dfs(i);
        }
    }
    
    cout << components.size() - 1 << "\n";
    for(int i = 1; i < components.size(); i++) {
        cout << components[i-1] << " " << components[i] << "\n";
    }
    
    return 0;
}