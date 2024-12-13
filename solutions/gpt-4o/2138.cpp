#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &postorder) {
    visited[node] = 1;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, postorder);
        }
    }
    postorder.push_back(node);
}

void reverseDfs(int node, vector<vector<int>> &reverse_adj, vector<int> &reachable) {
    reachable[node] = 1;
    for (int neighbor : reverse_adj[node]) {
        if (!reachable[neighbor]) {
            reverseDfs(neighbor, reverse_adj, reachable);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1), reverse_adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        reverse_adj[b].push_back(a);
    }

    vector<int> visited(n + 1, 0), postorder;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, adj, visited, postorder);
        }
    }

    vector<int> reach_count(n + 1, 0);
    for (int i = postorder.size() - 1; i >= 0; --i) {
        int node = postorder[i];
        vector<int> reachable(n + 1, 0);
        reverseDfs(node, reverse_adj, reachable);
        for (int j = 1; j <= n; ++j) {
            if (reachable[j]) {
                reach_count[node]++;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << reach_count[i] << " ";
    }
    cout << "\n";

    return 0;
}