#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

vector<int> adj[N];
long long subtree_size[N], total_dist[N];

void dfs1(int node, int parent) {
    subtree_size[node] = 1;
    for (int child : adj[node]) {
        if (child != parent) {
            dfs1(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
}

void dfs2(int node, int parent, int n) {
    for (int child : adj[node]) {
        if (child != parent) {
            total_dist[child] = total_dist[node] - subtree_size[child] + (n - subtree_size[child]);
            dfs2(child, node, n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0);

    total_dist[1] = 0;
    for (int child : adj[1]) {
        total_dist[1] += subtree_size[child];
    }

    dfs2(1, 0, n);

    for (int i = 1; i <= n; i++) {
        cout << total_dist[i] << " ";
    }

    return 0;
}