#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

vector<int> encodeTree(vector<vector<int>>& tree, int root) {
    vector<int> parent(tree.size(), -1);
    vector<vector<int>> children(tree.size());
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : tree[node]) {
            if (neighbor != parent[node]) {
                parent[neighbor] = node;
                children[node].push_back(neighbor);
                q.push(neighbor);
            }
        }
    }
    map<vector<int>, int> hashmap;
    int id = 0;
    function<int(int)> dfs = [&](int node) {
        vector<int> label;
        for (int child : children[node]) {
            label.push_back(dfs(child));
        }
        sort(label.begin(), label.end());
        if (hashmap.count(label) == 0) {
            hashmap[label] = id++;
        }
        return hashmap[label];
    };
    return dfs(root);
}

bool areIsomorphic(vector<vector<int>>& tree1, vector<vector<int>>& tree2) {
    int n = tree1.size();
    vector<int> encoding1 = encodeTree(tree1, 0);
    for (int root = 0; root < n; ++root) {
        vector<int> encoding2 = encodeTree(tree2, root);
        if (encoding1 == encoding2) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> tree1(n), tree2(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }
        cout << (areIsomorphic(tree1, tree2) ? "YES" : "NO") << '\n';
    }
    
    return 0;
}