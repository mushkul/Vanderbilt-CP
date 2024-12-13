#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int n, k1, k2;
 
vector<int> dfs_subtree(int node, int parent) {
    vector<int> subtree_paths = {0, 1};
 
    for (int child : graph[node]) {
        if (child == parent) continue;
 
        vector<int> child_paths = dfs_subtree(child, node);
        vector<int> new_paths(subtree_paths.size() + child_paths.size() - 1, 0);
 
        for (int i = 0; i < subtree_paths.size(); i++) {
            for (int j = 0; j < child_paths.size(); j++) {
                new_paths[i + j] += subtree_paths[i] * child_paths[j];
            }
        }
        subtree_paths = new_paths;
    }
 
    return subtree_paths;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> k1 >> k2;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    long long total_paths = 0;
    for (int root = 1; root <= n; root++) {
        vector<int> paths = dfs_subtree(root, 0);
        for (int k = k1; k <= k2 && k < paths.size(); k++) {
            total_paths += paths[k];
        }
    }
 
    cout << total_paths / 2 << "\n";
    return 0;
}