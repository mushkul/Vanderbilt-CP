#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
vector<int> adj[MAXN*2];
bool vis[MAXN*2];
int match[MAXN*2];
char grid[MAXN][MAXN];
int n;

bool dfs(int v) {
    if (vis[v]) return false;
    vis[v] = true;
    for (int u : adj[v]) {
        if (match[u] == -1 || dfs(match[u])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'o') {
                adj[i].push_back(j+n);
                adj[j+n].push_back(i);
            }
        }
    }

    memset(match, -1, sizeof(match));
    bool matched;
    do {
        matched = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) {
            if (match[i] == -1 && dfs(i)) {
                matched = true;
            }
        }
    } while (matched);

    vector<pair<int,int>> ans;
    bool used[MAXN*2] = {};
    
    for (int i = 0; i < n; i++) {
        if (match[i] != -1) {
            ans.push_back({1, i+1});
            used[i] = used[match[i]] = true;
        }
    }
    
    for (int j = n; j < 2*n; j++) {
        if (!used[j]) {
            ans.push_back({2, j-n+1});
        }
    }

    cout << ans.size() << "\n";
    for (auto [t,x] : ans) {
        cout << t << " " << x << "\n";
    }
}