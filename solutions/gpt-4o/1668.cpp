#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<int> team(n + 1, 0);
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        if (team[i] == 0) {
            queue<int> q;
            q.push(i);
            team[i] = 1;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if (team[v] == 0) {
                        team[v] = 3 - team[u];
                        q.push(v);
                    } else if (team[v] == team[u]) {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << team[i] << " ";
    }
    
    return 0;
}