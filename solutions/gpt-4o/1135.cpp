#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 200005;
const int LOG = 18;

vector<int> tree[MAXN];
int up[MAXN][LOG];
int depth[MAXN];

void dfs(int node, int parent) {
    up[node][0] = parent;
    for (int i = 1; i < LOG; ++i) {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }
    for (int neighbor : tree[node]) {
        if (neighbor != parent) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node);
        }
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
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
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    depth[1] = 0;
    dfs(1, 1);

    while (q--) {
        int a, b;
        cin >> a >> b;
        int ancestor = lca(a, b);
        int distance = depth[a] + depth[b] - 2 * depth[ancestor];
        cout << distance << "\n";
    }

    return 0;
}