#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int LOG = 20;

int n, q;
vector<int> adj[MAXN];
int value[MAXN];
int up[MAXN][LOG];
int in[MAXN], out[MAXN], timer = 0;
int depth[MAXN];
int max_val[LOG][MAXN];
vector<int> euler;

void dfs(int node, int parent, int dep) {
    in[node] = ++timer;
    euler.push_back(node);
    up[node][0] = parent;
    max_val[0][node] = value[node];
    depth[node] = dep;
    for (int i = 1; i < LOG; i++) {
        up[node][i] = up[up[node][i-1]][i-1];
        max_val[i][node] = max(max_val[i-1][node], max_val[i-1][up[node][i-1]]);
    }
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node, dep + 1);
    }
    out[node] = ++timer;
    euler.push_back(node);
}

bool is_ancestor(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (int i = LOG-1; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int query_max_path(int u, int v) {
    int l = lca(u, v);
    int res = value[l];
    
    for (int i = LOG-1; i >= 0; i--) {
        if (depth[u] - depth[l] >= (1 << i)) {
            res = max(res, max_val[i][u]);
            u = up[u][i];
        }
        if (depth[v] - depth[l] >= (1 << i)) {
            res = max(res, max_val[i][v]);
            v = up[v][i];
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0, 0);
    
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            value[s] = x;
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << query_max_path(a, b) << "\n";
        }
    }
    
    return 0;
}