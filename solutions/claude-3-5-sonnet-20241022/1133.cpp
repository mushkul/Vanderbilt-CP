#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 2e5+5;
vector<int> adj[MAX_N];
ll sub[MAX_N], ans[MAX_N], n;

void dfs1(int u, int p, int d) {
    sub[u] = 1;
    ans[1] += d;
    for(int v : adj[u]) {
        if(v != p) {
            dfs1(v, u, d+1);
            sub[u] += sub[v];
        }
    }
}

void dfs2(int u, int p) {
    for(int v : adj[u]) {
        if(v != p) {
            ans[v] = ans[u] + n - 2*sub[v];
            dfs2(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs1(1, 0, 0);
    dfs2(1, 0);
    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}