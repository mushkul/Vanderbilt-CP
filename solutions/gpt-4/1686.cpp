#include<bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 2e5;
vector<int> adj[maxn], radj[maxn], comp, comEg[maxn];
bool vis[maxn];
int coin[maxn], dp[maxn], val[maxn], tot = 0;

void addEdge(int u, int v){
    adj[u].push_back(v);
    radj[v].push_back(u);
}

void dfs1(int u){
    vis[u] = true;
    for(int v: adj[u])
        if(!vis[v])
            dfs1(v);
    comp.push_back(u);
}

void dfs2(int u){
    vis[u] = tot;
    val[tot] += coin[u];
    for(int v: radj[u])
        if(!vis[v])
            dfs2(v);
}

void solve(){
    int i, u, v, n, m;
    cin >> n >> m;
    for(i = 0; i < n; i++) cin >> coin[i];
    for(i = 0; i < m; i++){
        cin >> u >> v; u--; v--;
        addEdge(u, v);
    }
    memset(vis, false, sizeof vis);
    for(i = 0; i < n; i++)
        if(!vis[i])
            dfs1(i);
    memset(vis, false, sizeof vis);
    for(i = n-1; i >= 0; i--)
        if(!vis[comp[i]])
            dfs2(comp[i]), tot++;
    for(u = 0; u < n; u++)
        for(int v: adj[u]){
            if(vis[u] != vis[v])
                comEg[vis[u]].push_back(vis[v]);
        }
    int ans = 0;
    for(u = 0; u < tot; u++){
        for(int v: comEg[u]){
            dp[v] = max(dp[v], dp[u] + val[u]);
            ans = max(ans, dp[v]);
        }
    }
    for(i = 0; i < tot; i++)
        ans = max(ans, dp[i] + val[i]);
    cout << ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while(t--)
        solve();
    return 0;
}