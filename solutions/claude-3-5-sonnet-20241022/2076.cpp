#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<int> adj[MAX_N];
vector<pair<int,int>> bridges;
vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    
    for(int to : adj[v]) {
        if(to == p) continue;
        if(visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if(low[to] > tin[v]) {
                bridges.push_back({min(v,to), max(v,to)});
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    bridges.clear();
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i])
            dfs(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    find_bridges(n);
    
    cout << bridges.size() << "\n";
    for(auto bridge : bridges) {
        cout << bridge.first << " " << bridge.second << "\n";
    }
    
    return 0;
}