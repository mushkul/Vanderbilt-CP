#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
vector<int> result;
int vis[100005];

bool dfs(int node) {
    vis[node] = 1;
    for(int child : adj[node]) {
        if(vis[child] == 1) return true;
        if(vis[child] == 0 && dfs(child)) return true;
    }
    vis[node] = 2;
    result.push_back(node);
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
    }
    
    bool cycle = false;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            if(dfs(i)) {
                cycle = true;
                break;
            }
        }
    }
    
    if(cycle) {
        cout << "IMPOSSIBLE";
    } else {
        reverse(result.begin(), result.end());
        for(int x : result) {
            cout << x << " ";
        }
    }
    return 0;
}