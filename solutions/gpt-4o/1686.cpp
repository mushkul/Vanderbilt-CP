#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &order) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, order);
        }
    }
    order.push_back(u);
}

void dfs2(int u, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &component, vector<int> &coins, int &comp_sum) {
    visited[u] = true;
    component.push_back(u);
    comp_sum += coins[u];
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs2(v, adj, visited, component, coins, comp_sum);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    
    vector<vector<int>> adj(n), rev_adj(n);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }
    
    vector<bool> visited(n, false);
    vector<int> order;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, order);
        }
    }
    
    reverse(order.begin(), order.end());
    fill(visited.begin(), visited.end(), false);
    
    vector<int> component_id(n, -1);
    vector<int> component_coins;
    int scc_cnt = 0;
    
    for (int i : order) {
        if (!visited[i]) {
            vector<int> component;
            int comp_sum = 0;
            dfs2(i, rev_adj, visited, component, coins, comp_sum);
            for (int u : component) {
                component_id[u] = scc_cnt;
            }
            component_coins.push_back(comp_sum);
            ++scc_cnt;
        }
    }
    
    vector<vector<int>> dag(scc_cnt);
    vector<int> indegree(scc_cnt, 0);
    
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            if (component_id[u] != component_id[v]) {
                dag[component_id[u]].push_back(component_id[v]);
                ++indegree[component_id[v]];
            }
        }
    }
    
    vector<ll> dp(scc_cnt, 0);
    queue<int> q;
    
    for (int i = 0; i < scc_cnt; ++i) {
        dp[i] = component_coins[i];
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : dag[u]) {
            dp[v] = max(dp[v], dp[u] + component_coins[v]);
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    ll result = 0;
    for (ll val : dp) {
        result = max(result, val);
    }
    
    cout << result << endl;

    return 0;
}