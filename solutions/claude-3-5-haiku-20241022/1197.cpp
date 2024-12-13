#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    
    vector<int> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    dist[1] = 0;
    
    int cycleStart = -1;
    for (int i = 1; i <= n; i++) {
        cycleStart = -1;
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                if (i == n) {
                    cycleStart = v;
                    break;
                }
            }
        }
        if (cycleStart != -1) break;
    }
    
    if (cycleStart == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        
        for (int i = 1; i <= n; i++) {
            cycleStart = parent[cycleStart];
        }
        
        vector<int> cycle;
        int curr = cycleStart;
        do {
            cycle.push_back(curr);
            curr = parent[curr];
        } while (curr != cycleStart);
        
        cycle.push_back(cycleStart);
        reverse(cycle.begin(), cycle.end());
        
        for (int node : cycle) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}