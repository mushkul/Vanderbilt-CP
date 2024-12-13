#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e5 + 5;

vector<int> graph[MAX_N];
vector<int> rev_graph[MAX_N];
bool visited[MAX_N];
vector<int> order;
vector<int> component;
int scc_count[MAX_N];

void dfs1(int u) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u) {
    visited[u] = true;
    component.push_back(u);
    for (int v : rev_graph[u]) {
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    fill(visited, visited + MAX_N, false);
    reverse(order.begin(), order.end());

    int num_scc = 0;
    for (int u : order) {
        if (!visited[u]) {
            component.clear();
            dfs2(u);
            num_scc++;
            for (int v : component) {
                scc_count[v] = num_scc;
            }
        }
    }

    int connections = 0;
    for (int u = 1; u <= n; u++) {
        for (int v : graph[u]) {
            if (scc_count[u] != scc_count[v]) {
                connections++;
            }
        }
    }

    cout << connections << endl;

    return 0;
}