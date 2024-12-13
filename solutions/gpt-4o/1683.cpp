#include <bits/stdc++.h>
using namespace std;

void dfs1(int v, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &order) {
    visited[v] = true;
    for (int to : adj[v])
        if (!visited[to])
            dfs1(to, adj, visited, order);
    order.push(v);
}

void dfs2(int v, vector<vector<int>> &rev_adj, vector<bool> &visited, vector<int> &component, int comp_id) {
    visited[v] = true;
    component[v] = comp_id;
    for (int to : rev_adj[v])
        if (!visited[to])
            dfs2(to, rev_adj, visited, component, comp_id);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1), rev_adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    
    stack<int> order;
    vector<bool> visited(n + 1, false);
    
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i, adj, visited, order);
    
    fill(visited.begin(), visited.end(), false);
    vector<int> component(n + 1, 0);
    int k = 0;
    
    while (!order.empty()) {
        int v = order.top();
        order.pop();
        if (!visited[v]) {
            dfs2(v, rev_adj, visited, component, ++k);
        }
    }
    
    cout << k << "\n";
    for (int i = 1; i <= n; i++)
        cout << component[i] << " ";
    cout << "\n";
    
    return 0;
}