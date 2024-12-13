#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int subtree_size[MAXN];
int n;

void dfs_size(int node, int parent) {
    subtree_size[node] = 1;
    for (int child : graph[node]) {
        if (child != parent) {
            dfs_size(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
}

int find_centroid(int node, int parent) {
    for (int child : graph[node]) {
        if (child != parent) {
            if (subtree_size[child] > n / 2) {
                return find_centroid(child, node);
            }
        }
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs_size(1, 0);
    cout << find_centroid(1, 0) << endl;

    return 0;
}