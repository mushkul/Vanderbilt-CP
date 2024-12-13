#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxN = 2e5+10;
vector<ll> graph[maxN], level(maxN, 0), parent(maxN);
void DFS(ll source, ll prev);
void precompute_sparse_matrix(ll n);
ll LCA(ll u, ll v);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin>>n>>q;
    for (ll i = 0; i < n-1; ++i){
        ll a, b;
        cin>>a>>b;
        --a;
        --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    DFS(0, -1);
    precompute_sparse_matrix(n);
    while (q--){
        ll a, b;
        cin>>a>>b;
        --a;
        --b;
        ll lca = LCA(a, b);
        cout<<level[a] + level[b] - 2*level[lca]<<"\n";
    }
    return 0;
}

void DFS(ll source, ll prev){
    parent[source] = prev;
    for (auto u: graph[source]){
        if (u == prev) continue;
        level[u] = level[source] + 1;
        DFS(u, source);
    }
}

ll LOG[maxN+1];
ll dp[maxN][20];
void precompute_sparse_matrix(ll n){
    LOG[1] = 0;
    for (ll i = 2; i <= maxN; ++i) LOG[i] = LOG[i/2] + 1;
    for (ll i=0; i<n; ++i)
        dp[i][0] = parent[i];
    for (ll j=1; (1<<j)<n; ++j)
        for (ll i=0; i<n; ++i)
            dp[i][j] = dp[dp[i][j-1]][j-1];
}

ll LCA(ll u, ll v){
    if (level[u] < level[v]) swap(u, v);
    ll diff = level[u] - level[v];
    for (ll i=0; i<20; ++i)
        if ((diff>>i)&1)
            u = dp[u][i];
    if (u == v) return u;
    for (ll i=19; i>=0; --i)
        if (dp[u][i] != dp[v][i]){
            u = dp[u][i];
            v = dp[v][i];
        }
    return parent[u];
}