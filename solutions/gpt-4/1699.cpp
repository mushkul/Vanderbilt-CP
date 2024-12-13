C++
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);

const int maxn = 1e5+5;
vector<int> g[maxn], rg[maxn];
bool vis[maxn];
int order[maxn], c=0;
void dfs1(int v) {
    vis[v] = true;
    for (int u : rg[v]) {
        if (!vis[u]) dfs1(u);
    }
    order[c++] = v;
}

void dfs(int v) {
    vis[v] = true;
    for (int u : g[v]) {
        if (!vis[u]) dfs(u);
    }
}

int main() {
    fastIO;
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        rg[b].pb(a);
    }
    for (int i = 1;i <= n;i++) {
        if (!vis[i]) dfs1(i);
    }
    memset(vis, 0, sizeof(vis));
    int ans = -1;
    for (int i = n-1;i >= 0;i--) {
        if (!vis[order[i]]) {
            dfs(order[i]);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}