#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN], rev_graph[MAXN];
vector<int> order;
bool visited[MAXN];
int scc[MAXN], scc_count = 0;

void dfs1(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;
    scc[v] = scc_count;
    for (int u : rev_graph[v]) {
        if (!visited[u]) {
            dfs2(u);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev_graph[b].push_back(a);
    }
    
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    
    memset(visited, false, sizeof(visited));
    reverse(order.begin(), order.end());
    
    for (int v : order) {
        if (!visited[v]) {
            dfs2(v);
            scc_count++;
        }
    }
    
    vector<int> critical;
    for (int i = 1; i <= n; i++) {
        bool is_critical = true;
        for (int u : graph[i]) {
            if (scc[u] != scc[i]) {
                is_critical = false;
                break;
            }
        }
        if (is_critical && scc[i] == scc[n]) {
            critical.push_back(i);
        }
    }
    
    cout << critical.size() << "\n";
    for (int city : critical) {
        cout << city << " ";
    }
    cout << "\n";
    
    return 0;
}