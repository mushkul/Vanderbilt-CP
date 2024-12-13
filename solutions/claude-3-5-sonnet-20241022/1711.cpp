#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int INF = 1e9;

vector<int> adj[MAXN];
int cap[MAXN][MAXN], vis[MAXN], par[MAXN];
vector<vector<int>> paths;
int n, m;

bool bfs(int s, int t) {
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!vis[v] && cap[u][v] > 0) {
                vis[v] = 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    return vis[t];
}

void find_path(int s, int t) {
    vector<int> path;
    int cur = t;
    while (cur != s) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    paths.push_back(path);
}

int max_flow(int s, int t) {
    int flow = 0;
    while (bfs(s, t)) {
        flow++;
        int cur = t;
        while (cur != s) {
            int prev = par[cur];
            cap[prev][cur]--;
            cap[cur][prev]++;
            cur = prev;
        }
        find_path(s, t);
    }
    return flow;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b]++;
    }
    
    int k = max_flow(1, n);
    cout << k << "\n";
    
    for (auto path : paths) {
        cout << path.size() << "\n";
        for (int x : path) {
            cout << x << " ";
        }
        cout << "\n";
    }
    
    return 0;
}