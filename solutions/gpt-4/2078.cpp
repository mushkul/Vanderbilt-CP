#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

const int maxn = 5e5 + 5;
vector<int> vec[maxn], G[maxn];
ll f[maxn], inv[maxn], S[maxn], pw[maxn], a[maxn], n, m, deg[maxn], vis[maxn], dfn[maxn];
ll D(ll x) { return (x & 1) ? mod - 1 : 1; }
ll power(ll a,ll b) {
    ll ret = 1;
    for (; b; b >>= 1, a = a * a % mod) 
        if (b & 1) ret = ret * a % mod;
    return ret;
}
void Init() {
    for (int i = f[0] = 1; i <= n * 2; i++) 
        f[i] = f[i - 1] * i % mod;
    inv[n * 2] = power(f[n * 2],mod - 2);
    for (int i = n * 2 - 1; ~i; i--) 
        inv[i] = inv[i + 1] * (i + 1) % mod;
} 
ll C(int a,int b) {
    if (a < b) return 0;
    return f[a] * inv[a - b] % mod * inv[b] % mod;
}
ll g(int x,int y) {
    if (y < 0) return 0;
    return D(x) * C(x,y) % mod;
}
void Dfs(int u,int v = 0) {
    S[u] = 1;
    dfn[u] = 1;
    for (auto x : vec[u]) {
        if (x == v) continue;
        Dfs(x,u);
        S[u] += S[x];
    }
}
void INIT() {
    Init();
    Dfs(1);
    for (auto u : vec[1])
        if (!dfn[u]) G[a[u] = ++n].push_back(1);
    pw[0] = 1;
    for (int i = 1; i <= n; i++) 
        pw[i] = pw[i - 1] * 2 % mod;
}
void DP(int u,bool flag = 0,bool ft = 0) {
    vis[u] = 1;
    if (flag) 
        deg[u] += deg[G[u][0]], deg[G[u][0]] = deg[u];
    if (u != 1) a[u] = S[u] - ft;
    for (auto v : G[u]) 
        if (!vis[v]) DP(v,1,a[v] == a[u]);
}
int main() {
    cin>>n>>m;
    for (int i = 1, u, v; i <= m; i++) {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    INIT();
    DP(1);
    ll ans = pw[m];
    for (int i = 1; i <= n; i++) {
        ans = (ans + mod - pw[m - deg[i]] * (g(deg[i],a[i]) + g(deg[i],a[i] - 2)) % mod) % mod;
    }
    cout<<ans;
    return 0;
}