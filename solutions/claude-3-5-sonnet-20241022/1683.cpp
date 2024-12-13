#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj, rev_adj;
vector<bool> visited;
vector<int> order, kingdom;
int kingdoms = 0;

void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;
    kingdom[v] = kingdoms;
    for (int u : rev_adj[v]) {
        if (!visited[u]) {
            dfs2(u);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    adj.resize(n+1);
    rev_adj.resize(n+1);
    visited.assign(n+1, false);
    kingdom.resize(n+1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    
    visited.assign(n+1, false);
    reverse(order.begin(), order.end());
    
    for (int v : order) {
        if (!visited[v]) {
            kingdoms++;
            dfs2(v);
        }
    }
    
    cout << kingdoms << "\n";
    for (int i = 1; i <= n; i++) {
        cout << kingdom[i] << " ";
    }
    
    return 0;
}