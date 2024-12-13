#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN], condensed[MAXN];
int coins[MAXN], scc_coins[MAXN];
int disc[MAXN], low[MAXN], scc[MAXN], timer = 0, scc_count = 0;
bool in_stack[MAXN];
stack<int> st;

void tarjan(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    in_stack[u] = true;

    for (int v : graph[u]) {
        if (!disc[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (disc[u] == low[u]) {
        int total_coins = 0;
        while (true) {
            int curr = st.top();
            st.pop();
            in_stack[curr] = false;
            scc[curr] = scc_count;
            total_coins += coins[curr];

            if (curr == u) break;
        }
        scc_coins[scc_count] = total_coins;
        scc_count++;
    }
}

int solve_dag() {
    vector<int> in_degree(scc_count, 0);
    for (int u = 0; u < scc_count; u++) {
        for (int v : condensed[u]) {
            in_degree[v]++;
        }
    }

    vector<int> dp(scc_count, 0);
    queue<int> q;
    for (int i = 0; i < scc_count; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
            dp[i] = scc_coins[i];
        }
    }

    int max_coins = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        max_coins = max(max_coins, dp[u]);

        for (int v : condensed[u]) {
            dp[v] = max(dp[v], dp[u] + scc_coins[v]);
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return max_coins;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
    }

    for (int i = 0; i < n; i++) {
        if (!disc[i]) {
            tarjan(i);
        }
    }

    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            if (scc[u] != scc[v]) {
                condensed[scc[u]].push_back(scc[v]);
            }
        }
    }

    cout << solve_dag() << '\n';
    return 0;
}