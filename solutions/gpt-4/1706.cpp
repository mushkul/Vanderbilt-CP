#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100010];
int sz[100010], child[100010], vis[100010];
bitset<100010> dp, new_dp;

void getSize(int v, int par) {
    sz[v] = 1;
    for (auto u : adj[v]) {
        if (u != par && !vis[u]) {
            getSize(u, v);
            sz[v] += sz[u];
        }
    }
}

int getCentroid(int v, int par, int num) {
    for (auto u : adj[v]) {
        if (u != par && !vis[u] && sz[u]*2 > num)
            return getCentroid(u, v, num);
    }
    return v;
}

void solve(int root) {
    getSize(root, 0);
    int centroid = getCentroid(root, 0, sz[root]);
    dp = 0;
    dp[0] = 1;
    vis[centroid] = 1;
    int sum = 0;
    for (auto u : adj[centroid]) {
        if (vis[u]) continue;
        solve(u);
        sum += sz[u];
        new_dp = dp >> sz[u];
        new_dp |= dp;
        dp = new_dp;
    }
    for (int i = 0; i <= sum; ++i)
        if (dp[i])
            child[centroid] |= 1 << (30 - __builtin_clz(i));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1, a, b; i <= m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    solve(1);
    for (int i = 1; i <= n; ++i)
        cout << ((child[1] >> (30 - __builtin_clz(i))) & 1);
    cout << '\n';
    return 0;
}