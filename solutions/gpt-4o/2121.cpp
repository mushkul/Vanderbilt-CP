#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, r, c;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<Edge>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, r, c;
        cin >> a >> b >> r >> c;
        adj[a].push_back({b, r, c});
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
    dp[1][0] = 0;

    for (int u = 1; u <= n; ++u) {
        for (int j = 0; j <= k; ++j) {
            if (dp[u][j] == INF) continue;
            for (auto e : adj[u]) {
                for (int x = 1; x <= e.r && j + x <= k; ++x) {
                    dp[e.to][j + x] = min(dp[e.to][j + x], dp[u][j] + x * e.c);
                }
            }
        }
    }

    int answer = dp[n][k];
    if (answer == INF) answer = -1;
    cout << answer << endl;

    return 0;
}