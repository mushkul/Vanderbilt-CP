#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> dp1, dp2;

void dfs(int v, int parent) {
    for (int u : adj[v]) {
        if (u != parent) {
            dfs(u, v);
            dp1[v] += dp2[u];
            dp2[v] = max(dp2[v], dp1[u] + 1 - dp2[u]);
        }
    }
    dp2[v] += dp1[v];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    adj.resize(n + 1);
    dp1.resize(n + 1, 0);
    dp2.resize(n + 1, 0);
    
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);    
    cout << dp2[1] / 2 << '\n';
    return 0;
}