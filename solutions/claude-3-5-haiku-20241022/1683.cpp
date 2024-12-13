#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
vector<int> rev_graph[MAXN];
vector<int> order;
vector<bool> visited(MAXN);
int kingdom[MAXN];

void dfs_first(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs_first(u);
        }
    }
    order.push_back(v);
}

void dfs_second(int v, int k) {
    visited[v] = true;
    kingdom[v] = k;
    for (int u : rev_graph[v]) {
        if (!visited[u]) {
            dfs_second(u, k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    fill(visited.begin(), visited.end(), false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs_first(i);
        }
    }

    fill(visited.begin(), visited.end(), false);
    int k = 0;
    for (int i = order.size() - 1; i >= 0; i--) {
        if (!visited[order[i]]) {
            k++;
            dfs_second(order[i], k);
        }
    }

    cout << k << "\n";
    for (int i = 1; i <= n; i++) {
        cout << kingdom[i] << " ";
    }
    cout << "\n";

    return 0;
}