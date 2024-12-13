#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
int cnt[MAXN];
int depth[MAXN];
int parent[MAXN];

void dfs(int u, int par, int d) {
    parent[u] = par;
    depth[u] = d;
    for (int v : adj[u]) {
        if (v != par) {
            dfs(v, u, d + 1);
        }
    }
}

int lca(int a, int b) {
    while (depth[a] > depth[b]) a = parent[a];
    while (depth[b] > depth[a]) b = parent[b];
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        cnt[a]++;
        cnt[b]++;
        cnt[l]--;
        if (parent[l] != 0) cnt[parent[l]]--;
    }

    vector<int> result(n + 1);
    function<void(int, int)> count_paths = [&](int u, int par) {
        for (int v : adj[u]) {
            if (v != par) {
                count_paths(v, u);
                cnt[u] += cnt[v];
            }
        }
        result[u] = cnt[u];
    };

    count_paths(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}