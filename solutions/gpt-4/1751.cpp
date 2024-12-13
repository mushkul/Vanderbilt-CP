#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int vis[N], dist[N], c[N], a[N];
vector<int> adj[N];
int n, circle;

void dfs(int node) {
    vis[node] = 1;
    dist[node] = dist[a[node]] + 1;
    if (vis[a[node]] == 1) {
        c[node] = a[node];
        circle = dist[node] - dist[c[node]] + 1;
    }
    else if (vis[a[node]] == 2) {
        c[node] = c[a[node]];
    }
    else {
        dfs(a[node]);
        c[node] = (c[node] == 0 ? c[a[node]] : c[node]);
    }
    vis[node] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] - dist[c[i]] + circle << " ";
    }
    return 0;
}