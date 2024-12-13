#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
int maxDist = 0;
int farNode;

void dfs(int node, int dist) {
    vis[node] = true;
    if(dist > maxDist) {
        maxDist = dist;
        farNode = node;
    }
    for(int u : adj[node]) {
        if(!vis[u]) {
            dfs(u, dist + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    adj.resize(n+1);
    vis.resize(n+1);
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    maxDist = 0;
    dfs(1, 0);
    
    fill(vis.begin(), vis.end(), false);
    maxDist = 0;
    dfs(farNode, 0);
    
    cout << maxDist << "\n";
    
    return 0;
}