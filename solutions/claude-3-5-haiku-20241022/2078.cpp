#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

int n, m;
vector<int> graph[MAXN];
bool used_edge[MAXN * 2];

int count_eulerian_subgraphs() {
    int total_subgraphs = 1;
    
    for (int mask = 0; mask < (1 << m); mask++) {
        fill(used_edge, used_edge + m, false);
        vector<int> degree(n + 1, 0);
        
        for (int j = 0; j < m; j++) {
            if (mask & (1 << j)) {
                int u = graph[j][0];
                int v = graph[j][1];
                degree[u]++;
                degree[v]++;
                used_edge[j] = true;
            }
        }
        
        bool is_eulerian = true;
        for (int i = 1; i <= n; i++) {
            if (degree[i] % 2 != 0) {
                is_eulerian = false;
                break;
            }
        }
        
        if (is_eulerian) {
            total_subgraphs++;
            total_subgraphs %= MOD;
        }
    }
    
    return total_subgraphs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[i] = {u, v};
    }
    
    cout << count_eulerian_subgraphs() << "\n";
    
    return 0;
}