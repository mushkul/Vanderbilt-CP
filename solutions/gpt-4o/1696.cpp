#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1005;
int n, m, k;
vector<int> adj[MAXN];
int pairU[MAXN], pairV[MAXN], dist[MAXN];

bool bfs() {
    queue<int> q;

    for (int u = 1; u <= n; ++u) {
        if (pairU[u] == 0) {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = INT_MAX;
        }
    }
    dist[0] = INT_MAX;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] < dist[0]) {
            for (int v : adj[u]) {
                if (dist[pairV[v]] == INT_MAX) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return (dist[0] != INT_MAX);
}

bool dfs(int u) {
    if (u != 0) {
        for (int v : adj[u]) {
            if (dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INT_MAX;
        return false;
    }
    return true;
}

int hopcroftKarp() {
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));

    int matching = 0;
    while (bfs()) {
        for (int u = 1; u <= n; ++u) {
            if (pairU[u] == 0 && dfs(u)) {
                ++matching;
            }
        }
    }
    return matching;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    int r = hopcroftKarp();
    cout << r << endl;
    for (int u = 1; u <= n; ++u) {
        if (pairU[u] != 0) {
            cout << u << " " << pairU[u] << endl;
        }
    }

    return 0;
}