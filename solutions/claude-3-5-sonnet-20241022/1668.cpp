#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> team;
bool possible = true;

void dfs(int v, int t) {
    team[v] = t;
    for (int u : adj[v]) {
        if (team[u] == -1) {
            dfs(u, 3-t);
        } else if (team[u] == t) {
            possible = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    adj.resize(n+1);
    team.assign(n+1, -1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (team[i] == -1) {
            dfs(i, 1);
        }
    }
    
    if (!possible) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << team[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}