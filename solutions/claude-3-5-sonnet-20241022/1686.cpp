#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;
vector<int> adj[MAXN];
vector<int> adjT[MAXN];
vector<bool> visited;
vector<int> order;
vector<int> component;
vector<vector<int>> scc;
vector<ll> coins;
ll dp[MAXN];

void dfs1(int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;
    component.push_back(v);
    for (auto u : adjT[v]) {
        if (!visited[u])
            dfs2(u);
    }
}

ll dfs3(int v, vector<vector<int>>& sccGraph, vector<ll>& sccWeight) {
    if (dp[v] != -1)
        return dp[v];
        
    dp[v] = sccWeight[v];
    ll maxPath = 0;
    for (auto u : sccGraph[v]) {
        maxPath = max(maxPath, dfs3(u, sccGraph, sccWeight));
    }
    return dp[v] += maxPath;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    coins.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }
    
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs1(i);
    }
    
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    
    for (auto v : order) {
        if (!visited[v]) {
            dfs2(v);
            scc.push_back(component);
            component.clear();
        }
    }
    
    vector<ll> sccWeight(scc.size());
    vector<int> nodeToScc(n);
    for (int i = 0; i < scc.size(); i++) {
        for (auto v : scc[i]) {
            sccWeight[i] += coins[v];
            nodeToScc[v] = i;
        }
    }
    
    vector<vector<int>> sccGraph(scc.size());
    set<pair<int,int>> edges;
    for (int v = 0; v < n; v++) {
        for (auto u : adj[v]) {
            int sccV = nodeToScc[v];
            int sccU = nodeToScc[u];
            if (sccV != sccU && edges.count({sccV, sccU}) == 0) {
                edges.insert({sccV, sccU});
                sccGraph[sccV].push_back(sccU);
            }
        }
    }
    
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 0; i < scc.size(); i++) {
        ans = max(ans, dfs3(i, sccGraph, sccWeight));
    }
    
    cout << ans << "\n";
    
    return 0;
}