#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200000;
const int LOG = 18;

vector<int> tree[MAXN + 1];
int up[MAXN + 1][LOG];
int depth[MAXN + 1];

void dfs(int v, int p, int d) {
    up[v][0] = p;
    depth[v] = d;
    for (int i = 1; i < LOG; ++i) {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (int u : tree[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; ++i) {
        if ((diff >> i) & 1) {
            a = up[a][i];
        }
    }
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }
    
    dfs(1, 1, 0);
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    
    return 0;
}