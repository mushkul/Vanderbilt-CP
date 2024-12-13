#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[200001];
int subtreeSize[200001];
long long pathsThrough[200001];
long long result[200001];

void dfs(int node, int parent) {
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node);
        subtreeSize[node] += subtreeSize[neighbor];
    }
}

void dfs2(int node, int parent, long long parent_paths) {
    result[node] = pathsThrough[node] + parent_paths;
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        dfs2(neighbor, node, result[node] - subtreeSize[neighbor]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        subtreeSize[i] = 0;
        pathsThrough[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        subtreeSize[a]++;
        subtreeSize[b]++;
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) {
        for (int neighbor : adj[i]) {
            if (neighbor > i) {
                pathsThrough[i] += subtreeSize[neighbor] * (subtreeSize[1] - subtreeSize[neighbor]);
            }
        }
    }

    dfs2(1, 0, 0);

    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}