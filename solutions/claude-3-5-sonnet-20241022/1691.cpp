#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<pair<int,int>> adj[MAXN];
int degree[MAXN];
vector<int> path;
vector<bool> used;

void euler(int u) {
    while (!adj[u].empty()) {
        auto [v, id] = adj[u].back();
        adj[u].pop_back();
        if (used[id]) continue;
        used[id] = true;
        euler(v);
    }
    path.push_back(u);
}

int main() {
    int n, m;
    cin >> n >> m;
    used.resize(m);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        degree[a]++;
        degree[b]++;
    }
    
    bool possible = true;
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2) {
            possible = false;
            break;
        }
    }
    
    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    euler(1);
    
    if (path.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    reverse(path.begin(), path.end());
    for (int x : path) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}