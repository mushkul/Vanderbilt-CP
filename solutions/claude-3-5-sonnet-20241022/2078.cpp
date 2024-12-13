#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int n, m;
vector<vector<int>> g;
vector<vector<int>> basis;
vector<int> edge_seen;

void gauss_xor() {
    for(int i = 0; i < basis.size(); i++) {
        int lead = -1;
        for(int j = 0; j < m; j++) {
            if(basis[i][j]) {
                lead = j;
                break;
            }
        }
        if(lead == -1) {
            basis.erase(basis.begin() + i);
            i--;
            continue;
        }
        
        for(int j = 0; j < basis.size(); j++) {
            if(i != j && basis[j][lead]) {
                for(int k = lead; k < m; k++) {
                    basis[j][k] ^= basis[i][k];
                }
            }
        }
    }
}

void add_cycle(vector<int>& cycle) {
    basis.push_back(cycle);
    gauss_xor();
}

void dfs(int v, int p, vector<int>& path, vector<bool>& vis) {
    vis[v] = true;
    path.push_back(v);
    
    for(int i = 0; i < g[v].size(); i++) {
        int e = g[v][i]/2;
        int u = g[v][i]%2 ? v : edge_seen[e];
        
        if(edge_seen[e] == -1) {
            edge_seen[e] = v;
            continue;
        }
        
        if(u == p || edge_seen[e] == v) continue;
        
        if(!vis[u]) {
            dfs(u, v, path, vis);
        } else {
            vector<int> cycle(m);
            int start = find(path.begin(), path.end(), u) - path.begin();
            for(int j = start; j < path.size()-1; j++) {
                for(int k = 0; k < g[path[j]].size(); k++) {
                    if(g[path[j]][k]/2 == e) {
                        cycle[e] = 1;
                        break;
                    }
                }
                e = -1;
                for(int k = 0; k < g[path[j+1]].size(); k++) {
                    if(g[path[j+1]][k]/2 != e && 
                       (g[path[j+1]][k]%2 ? path[j+1] : edge_seen[g[path[j+1]][k]/2]) == path[j]) {
                        e = g[path[j+1]][k]/2;
                        cycle[e] = 1;
                        break;
                    }
                }
            }
            add_cycle(cycle);
        }
    }
    path.pop_back();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    g.resize(n+1);
    edge_seen.assign(m, -1);
    
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(2*i);
        g[b].push_back(2*i+1);
    }
    
    vector<int> path;
    vector<bool> vis(n+1);
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, 0, path, vis);
        }
    }
    
    ll ans = 1;
    for(int i = 0; i < m - basis.size(); i++) {
        ans = (ans * 2) % MOD;
    }
    
    cout << ans << "\n";
    
    return 0;
}