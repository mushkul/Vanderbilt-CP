#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree;
vector<int> subtree_size;

void dfs(int node, int parent) {
    subtree_size[node] = 1;
    for (int neighbor : tree[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node);
        subtree_size[node] += subtree_size[neighbor];
    }
}

int find_centroid(int node, int parent, int total_nodes) {
    for (int neighbor : tree[node]) {
        if (neighbor != parent && subtree_size[neighbor] > total_nodes / 2) {
            return find_centroid(neighbor, node, total_nodes);
        }
    }
    return node;
}

int main() {
    int n;
    cin >> n;
    tree.resize(n + 1);
    subtree_size.resize(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1, -1);
    int centroid = find_centroid(1, -1, n);
    cout << centroid << endl;
    
    return 0;
}