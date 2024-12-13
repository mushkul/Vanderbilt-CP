#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
vector<int> reverse_graph[MAXN];
bool visited[MAXN];

void dfs(int node, vector<int> adj[], bool mark[]) {
    mark[node] = true;
    for (int next : adj[node]) {
        if (!mark[next]) {
            dfs(next, adj, mark);
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
        reverse_graph[b].push_back(a);
    }

    memset(visited, 0, sizeof(visited));
    dfs(1, graph, visited);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO\n" << 1 << " " << i << "\n";
            return 0;
        }
    }

    memset(visited, 0, sizeof(visited));
    dfs(1, reverse_graph, visited);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO\n" << i << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}