#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, const vector<vector<int>>& tree, vector<int>& subordinates) {
    for (int v : tree[u]) {
        dfs(v, tree, subordinates);
        subordinates[u] += 1 + subordinates[v];
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    for (int i = 2; i <= n; ++i) {
        int boss;
        cin >> boss;
        tree[boss].push_back(i);
    }
    vector<int> subordinates(n + 1, 0);
    dfs(1, tree, subordinates);
    for (int i = 1; i <= n; ++i) {
        cout << subordinates[i] << " ";
    }
    return 0;
}