#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int dp[MAXN];
vector<int> order;
bool visited[MAXN];

void topologicalSort(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            topologicalSort(u);
        }
    }
    order.push_back(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            topologicalSort(i);
        }
    }

    reverse(order.begin(), order.end());

    dp[1] = 1;
    for (int v : order) {
        for (int u : adj[v]) {
            dp[u] = (dp[u] + dp[v]) % MOD;
        }
    }

    cout << dp[n] << "\n";

    return 0;
}