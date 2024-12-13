#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<int> adj[MAX_N];
vector<pair<int,int>> edges;
bool vis[MAX_N], vis2[MAX_N];
int n, m;

void dfs(int node) {
    vis[node] = true;
    for(int next : adj[node]) {
        if(!vis[next]) {
            dfs(next);
        }
    }
}

void dfs2(int node, vector<int> g[]) {
    vis2[node] = true;
    for(int next : g[node]) {
        if(!vis2[next]) {
            dfs2(next, g);
        }
    }
}

bool isConnected() {
    memset(vis, false, sizeof(vis));
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) return false;
    }
    return true;
}

bool isStronglyConnected(vector<vector<int>>& dir_edges) {
    vector<int> g[MAX_N];
    for(auto e : dir_edges) {
        g[e[0]].push_back(e[1]);
    }
    
    for(int i = 1; i <= n; i++) {
        memset(vis2, false, sizeof(vis2));
        dfs2(i, g);
        for(int j = 1; j <= n; j++) {
            if(!vis2[j]) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a,b});
    }
    
    if(!isConnected()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    if(m < n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    vector<vector<int>> dir_edges;
    
    // Try to create a cycle using all nodes
    for(int i = 1; i < n; i++) {
        bool found = false;
        for(auto e : edges) {
            if(e.first == i && e.second == i+1) {
                dir_edges.push_back({i, i+1});
                found = true;
                break;
            }
            if(e.second == i && e.first == i+1) {
                dir_edges.push_back({i, i+1});
                found = true;
                break;
            }
        }
        if(!found) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    
    bool found = false;
    for(auto e : edges) {
        if(e.first == n && e.second == 1) {
            dir_edges.push_back({n, 1});
            found = true;
            break;
        }
        if(e.second == n && e.first == 1) {
            dir_edges.push_back({n, 1});
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    // Add remaining edges in any direction
    for(auto e : edges) {
        bool exists = false;
        for(auto de : dir_edges) {
            if((de[0] == e.first && de[1] == e.second) || 
               (de[0] == e.second && de[1] == e.first)) {
                exists = true;
                break;
            }
        }
        if(!exists) {
            dir_edges.push_back({e.first, e.second});
        }
    }
    
    if(!isStronglyConnected(dir_edges)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for(auto e : dir_edges) {
        cout << e[0] << " " << e[1] << "\n";
    }
    
    return 0;
}