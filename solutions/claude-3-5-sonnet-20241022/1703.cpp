#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<int> adj[MAX_N], adjRev[MAX_N];
vector<int> critical;
bool vis[MAX_N], visRev[MAX_N];
int n, m;

void dfs(int u) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) dfs(v);
    }
}

void dfsRev(int u) {
    visRev[u] = true;
    for(int v : adjRev[u]) {
        if(!visRev[v]) dfsRev(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adjRev[b].push_back(a);
    }
    
    dfs(1);
    dfsRev(n);
    
    for(int i = 1; i <= n; i++) {
        if(vis[i] && visRev[i]) {
            memset(vis, false, sizeof(vis));
            
            int x = i;
            
            dfs(1);
            
            bool isCritical = false;
            for(int j = 1; j <= n; j++) {
                if(j != x && visRev[j] && !vis[j]) {
                    isCritical = true;
                    break;
                }
            }
            
            if(isCritical) {
                critical.push_back(i);
            }
        }
    }
    
    cout << critical.size() << "\n";
    for(int x : critical) {
        cout << x << " ";
    }
    
    return 0;
}