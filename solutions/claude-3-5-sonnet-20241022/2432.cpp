#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
int n;
int row[MAXN], col[MAXN];
bool vis[MAXN][MAXN];
bool used[MAXN];
vector<int> adj[MAXN];
int match[MAXN];

bool dfs(int u) {
    for (int v : adj[u]) {
        if (used[v]) continue;
        used[v] = true;
        if (match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

bool solve() {
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += row[i];
        sum2 += col[i];
    }
    if (sum1 != sum2) return false;

    memset(match, -1, sizeof(match));
    vector<pair<int,int>> edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < row[i]; j++) {
            edges.push_back({i, j});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col[i]; j++) {
            int u = edges[edges.size()-1-j].first;
            adj[u].push_back(i);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        memset(used, 0, sizeof(used));
        if (dfs(i)) cnt++;
    }

    if (cnt != sum1) return false;

    for (int i = 0; i < n; i++) {
        int need = col[i];
        for (int j = 0; j < n; j++) {
            if (match[i] == j) {
                vis[j][i] = 1;
                need--;
            }
        }
        if (need != 0) return false;
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> row[i];
    for (int i = 0; i < n; i++) cin >> col[i];

    if (!solve()) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (vis[i][j] ? 'X' : '.');
        }
        cout << endl;
    }
    
    return 0;
}