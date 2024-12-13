#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> buildTree(int n) {
    vector<vector<int>> tree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    return tree;
}

vector<int> findSubtreeSizes(const vector<vector<int>>& tree, int node, int parent) {
    vector<int> sizes = {1};
    for (int child : tree[node]) {
        if (child != parent) {
            vector<int> childSizes = findSubtreeSizes(tree, child, node);
            sizes.insert(sizes.end(), childSizes.begin(), childSizes.end());
        }
    }
    sort(sizes.begin(), sizes.end());
    return sizes;
}

bool isIsomorphic(const vector<vector<int>>& tree1, const vector<vector<int>>& tree2, int n) {
    vector<int> subtree1 = findSubtreeSizes(tree1, 1, 0);
    vector<int> subtree2 = findSubtreeSizes(tree2, 1, 0);
    return subtree1 == subtree2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> tree1 = buildTree(n);
        vector<vector<int>> tree2 = buildTree(n);

        cout << (isIsomorphic(tree1, tree2, n) ? "YES" : "NO") << "\n";
    }

    return 0;
}