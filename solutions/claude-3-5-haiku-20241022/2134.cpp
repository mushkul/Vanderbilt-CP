#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 20;

vector<int> graph[MAXN];
int depth[MAXN], parent[MAXN][LOG], values[MAXN];
int n, q;

void dfs(int node, int par, int d) {
    depth[node] = d;
    parent[node][0] = par;
    
    for (int i = 1; i < LOG; i++) {
        parent[node][i] = parent[parent[node][i-1]][i-1];
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
        if (depth[a] - (1 << i) >= depth[b]) {
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

int path_max(int a, int b) {
    int l = lca(a, b);
    int maxVal = 0;
    
    while (a != l) {
        maxVal = max(maxVal, values[a]);
        a = parent[a][0];
    }
    
    while (b != l) {
        maxVal = max(maxVal, values[b]);
        b = parent[b][0];
    }
    
    maxVal = max(maxVal, values[l]);
    return maxVal;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> q;
    
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0, 0);
    
    while (q--) {
        int type, a, b;
        cin >> type;
        
        if (type == 1) {
            cin >> a >> b;
            values[a] = b;
        } else {
            cin >> a >> b;
            cout << path_max(a, b) << '\n';
        }
    }
    
    return 0;
}