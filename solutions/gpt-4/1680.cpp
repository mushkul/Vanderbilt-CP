#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
vector<int> edge[mxN], path;
bool visited[mxN];
int dist[mxN], prevNode[mxN];

void dfs(int node) {
    visited[node] = true;
    for (auto i : edge[node]) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    path.push_back(node);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b, --a, --b;
        edge[a].push_back(b);
    }
    dfs(0);
    for (int i=0; i<n; ++i) {
        if (dist[path[i]]+1 > dist[edge[path[i]][j]]) {
            dist[edge[path[i]][j]] = dist[path[i]]+1;
            prevNode[edge[path[i]][j]] = path[i];
        }
    }
    if (dist[n-1] == -1) {
        cout << "IMPOSSIBLE" << "\n";
    } 
    else {
        vector<int> ans;
        for (int j=n-1; ~j; j = prevNode[j]) {
            ans.push_back(j+1);
        }
        cout << dist[n-1] + 1 << "\n";
        for (int i = ans.size() - 1; ~i; --i) {
            cout << ans[i] << " ";
        }
    }
    return 0;
}