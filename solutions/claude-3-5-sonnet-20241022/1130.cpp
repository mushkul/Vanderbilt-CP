#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
vector<int> g[N];
int dp[N][2];
 
void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = 0;
    
    for(int v : g[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
    }
    
    for(int v : g[u]) {
        if(v == p) continue;
        dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << '\n';
    
    return 0;
}