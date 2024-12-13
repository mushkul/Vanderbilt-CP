#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
vector<bool> visited;
vector<int> parent;
int start, finish;

bool dfs(int node, int par) {
    visited[node] = true;
    parent[node] = par;
    
    for(int next : adj[node]) {
        if(next == par) continue;
        
        if(visited[next]) {
            start = next;
            finish = node;
            return true;
        }
        
        if(dfs(next, node))
            return true;
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    visited.resize(n+1);
    parent.resize(n+1);
    start = -1;
    finish = -1;
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1))
                break;
        }
    }
    
    if(start == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    vector<int> cycle;
    cycle.push_back(start);
    for(int v = finish; v != start; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(start);
    
    cout << cycle.size() << "\n";
    for(int v : cycle)
        cout << v << " ";
        
    return 0;
}