#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;

vector<int> graph[MAXN];
int depth[MAXN];
int parent[MAXN][LOG];

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node][0] = par;
    
    for (int i = 1; i < LOG; i++) {
        if (parent[node][i-1] != 0) {
            parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }
    
    for (int child : graph[node]) {
        if (child != par) {
            dfs(child, node, d + 1);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != 0 && depth[parent[a][i]] >= depth[b]) {
            a = parent[a][i];
        }
    }
    
    if (a == b) return a;
    
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    
    return parent[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0, 0);
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[l] << "\n";
    }
    
    return 0;
}