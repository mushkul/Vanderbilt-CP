#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int n, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(n + 1);
    vector<int> inDegree(n + 1, 0);
    vector<int> order;

    for (auto& pre : prerequisites) {
        adj[pre.first].push_back(pre.second);
        inDegree[pre.second]++;
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.top();
        q.pop();
        order.push_back(curr);

        for (int neighbor : adj[curr]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return order;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> prerequisites(m);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        prerequisites[i] = {a, b};
    }
    
    vector<int> result = findOrder(n, prerequisites);
    
    for (int i = 0; i < n; ++i) {
        cout << result[i];
        if (i < n - 1) cout << " ";
    }
    
    return 0;
}