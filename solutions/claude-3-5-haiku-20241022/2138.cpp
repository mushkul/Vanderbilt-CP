#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e4 + 5;
vector<int> graph[MAXN];
int reachable[MAXN];
bool visited[MAXN];

void dfs(int node) {
    visited[node] = true;
    reachable[node]++;
    
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
        reachable[node] += reachable[neighbor];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << reachable[i] << " ";
    }
    
    return 0;
}