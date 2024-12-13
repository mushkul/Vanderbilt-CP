#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> graph[MAXN];
int visited[MAXN];
int parent[MAXN];
vector<int> cycle;

bool dfs(int node, int prev) {
    visited[node] = 1;
    parent[node] = prev;
    
    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            if (dfs(neighbor, node)) {
                return true;
            }
        }
        else if (visited[neighbor] == 1) {
            int current = node;
            cycle.push_back(neighbor);
            
            while (current != neighbor) {
                cycle.push_back(current);
                current = parent[current];
            }
            
            cycle.push_back(neighbor);
            reverse(cycle.begin(), cycle.end());
            
            return true;
        }
    }
    
    visited[node] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, 0)) {
                cout << cycle.size() << "\n";
                for (int city : cycle) {
                    cout << city << " ";
                }
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE";
    return 0;
}