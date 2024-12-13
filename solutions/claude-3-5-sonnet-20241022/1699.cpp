#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN], trans[MAXN];
vector<bool> vis;
vector<int> comp;
int n, m, scc_count;

void dfs1(int v, vector<int>& order) {
    vis[v] = true;
    for(int u : adj[v]) {
        if(!vis[u]) {
            dfs1(u, order);
        }
    }
    order.push_back(v);
}

void dfs2(int v, int c) {
    comp[v] = c;
    for(int u : trans[v]) {
        if(comp[u] == -1) {
            dfs2(u, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    vector<pair<int,int>> edges;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        edges.push_back({a, b});
        adj[a].push_back(b);
        trans[b].push_back(a);
    }
    
    vis.assign(n, false);
    vector<int> order;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs1(i, order);
        }
    }
    
    comp.assign(n, -1);
    scc_count = 0;
    for(int i = n-1; i >= 0; i--) {
        int v = order[i];
        if(comp[v] == -1) {
            dfs2(v, scc_count++);
        }
    }
    
    vector<vector<bool>> reach(scc_count, vector<bool>(scc_count, false));
    for(auto [a, b] : edges) {
        reach[comp[a]][comp[b]] = true;
    }
    
    int ans = 0;
    for(auto [a, b] : edges) {
        if(comp[a] != comp[b] && !reach[comp[a]][comp[b]]) {
            ans++;
            reach[comp[a]][comp[b]] = true;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}