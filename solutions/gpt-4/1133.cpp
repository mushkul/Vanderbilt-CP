#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> g[maxn];
long long son[maxn], dp[maxn];
int n;

void dfs1(int u, int fa)
{
    dp[u] = 0, son[u] = 1;
    for(auto v : g[u]) if(v != fa)
    {
        dfs1(v, u);
        dp[u] += dp[v] + son[v];
        son[u] += son[v];
    }
}

void dfs2(int u, int fa)
{
    for(auto v : g[u]) if(v != fa)
    {
        dp[v] = dp[u] + n - 2 * son[v];
        dfs2(v, u);
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; ++i) cout << dp[i] << " ";
    cout << "\n";
    return 0;
}