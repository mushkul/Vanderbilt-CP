#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    vector<int> team(n + 1, 0);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) {
            queue<int> q;
            q.push(i);
            team[i] = 1;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (int neighbor : graph[curr]) {
                    if (team[neighbor] == 0) {
                        team[neighbor] = (team[curr] == 1) ? 2 : 1;
                        q.push(neighbor);
                    }
                    else if (team[neighbor] == team[curr]) {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << team[i] << " ";
    }
    cout << endl;
    
    return 0;
}