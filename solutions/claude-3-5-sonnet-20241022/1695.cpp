#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
const int INF = 1e9;

vector<int> adj[MAXN];
int capacity[MAXN][MAXN];
int n, m;

vector<int> bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                q.push(next);
            }
        }
    }
    return parent;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n+1);
    
    while (true) {
        bfs(s, t, parent);
        if (parent[t] == -1) break;
        
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur]--;
            capacity[cur][prev]++;
            cur = prev;
        }
        flow++;
    }
    return flow;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] = 1;
        capacity[b][a] = 1;
    }
    
    int k = maxflow(1, n);
    cout << k << "\n";
    
    vector<bool> reachable(n+1);
    queue<int> q;
    q.push(1);
    reachable[1] = true;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int next : adj[cur]) {
            if (!reachable[next] && capacity[cur][next]) {
                reachable[next] = true;
                q.push(next);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j : adj[i]) {
            if (reachable[i] && !reachable[j] && capacity[j][i]) {
                cout << i << " " << j << "\n";
            }
        }
    }
    
    return 0;
}