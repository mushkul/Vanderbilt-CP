#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXLOG = 20;

int up[MAXN][MAXLOG];
int depth[MAXN];
vector<int> adj[MAXN];

void dfs(int node, int parent) {
    up[node][0] = parent;
    for(int i = 1; i < MAXLOG; i++) {
        up[node][i] = up[up[node][i-1]][i-1];
    }
    
    for(int child : adj[node]) {
        if(child != parent) {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
}

int getLCA(int a, int b) {
    if(depth[a] < depth[b])
        swap(a, b);
    
    int diff = depth[a] - depth[b];
    
    for(int i = 0; i < MAXLOG; i++) {
        if((diff >> i) & 1) {
            a = up[a][i];
        }
    }
    
    if(a == b)
        return a;
        
    for(int i = MAXLOG-1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }
    
    depth[1] = 0;
    dfs(1, 1);
    
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << getLCA(a, b) << "\n";
    }
    
    return 0;
}