#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 100000;

vector<int> adj[MAXN + 1];
vector<int> rev_adj[MAXN + 1];
bool visited[MAXN + 1];
vector<int> order;
int component[MAXN + 1];

void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int comp) {
    component[v] = comp;
    for (int u : rev_adj[v]) {
        if (component[u] == 0)
            dfs2(u, comp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs1(i);
    }

    reverse(order.begin(), order.end());
    int comp = 0;

    for (int v : order) {
        if (component[v] == 0)
            dfs2(v, ++comp);
    }

    vector<int> in(comp + 1, 0), out(comp + 1, 0);
    for (int v = 1; v <= n; ++v) {
        for (int u : adj[v]) {
            if (component[v] != component[u]) {
                out[component[v]]++;
                in[component[u]]++;
            }
        }
    }

    int connect_in = 0, connect_out = 0;
    for (int i = 1; i <= comp; ++i) {
        if (in[i] == 0) connect_in++;
        if (out[i] == 0) connect_out++;
    }

    cout << max(connect_in, connect_out) << "\n";

    int last_in = 0, last_out = 0;
    for (int i = 1; i <= comp; ++i) {
        if (in[i] == 0) last_in = i;
        if (out[i] == 0) last_out = i;
    }

    for (int i = 1, j = 1; i <= comp && j <= comp;) {
        while (i <= comp && in[i] != 0) i++;
        while (j <= comp && out[j] != 0) j++;
        if (i <= comp && j <= comp) {
            if (i != j || (i == last_in && j == last_out)) {
                cout << order[find(component + 1, component + n + 1, j) - component] << " "
                     << order[find(component + 1, component + n + 1, i) - component] << "\n";
                in[i] = -1;
                out[j] = -1;
            } else if (comp > 1) {
                int tmp = (i % comp) + 1;
                while (tmp == j || in[tmp] == -1 || out[tmp] != 0) tmp = (tmp % comp) + 1;
                cout << order[find(component + 1, component + n + 1, j) - component] << " "
                     << order[find(component + 1, component + n + 1, tmp) - component] << "\n";
                out[j] = -1;
            }
        }
    }
    return 0;
}