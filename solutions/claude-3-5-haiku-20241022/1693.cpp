#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
vector<int> edges[MAXN];
int in_degree[MAXN], out_degree[MAXN];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        edges[a].push_back(b);
        out_degree[a]++;
        in_degree[b]++;
    }
    
    for (int i = 2; i < n; ++i) {
        if (in_degree[i] != out_degree[i]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    
    if (out_degree[1] != in_degree[1] + 1 || in_degree[n] != out_degree[n] + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    vector<int> path;
    function<void(int)> dfs = [&](int node) {
        while (!graph[node].empty()) {
            int next = graph[node].back();
            graph[node].pop_back();
            dfs(next);
        }
        path.push_back(node);
    };
    
    dfs(1);
    
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    reverse(path.begin(), path.end());
    
    for (int x : path) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}