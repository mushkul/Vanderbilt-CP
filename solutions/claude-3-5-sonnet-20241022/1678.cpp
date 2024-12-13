#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis, recStack;
int n, m;
vector<int> parent;
vector<int> cycle;

bool dfs(int node) {
    vis[node] = true;
    recStack[node] = true;
    
    for(auto &child : adj[node]) {
        if(!vis[child]) {
            parent[child] = node;
            if(dfs(child))
                return true;
        }
        else if(recStack[child]) {
            int cur = node;
            cycle.push_back(child);
            while(cur != child) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(child);
            return true;
        }
    }
    
    recStack[node] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1);
    recStack.resize(n+1);
    parent.resize(n+1);
    
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            if(dfs(i)) {
                reverse(cycle.begin(), cycle.end());
                cout << cycle.size() << "\n";
                for(auto &x : cycle)
                    cout << x << " ";
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}