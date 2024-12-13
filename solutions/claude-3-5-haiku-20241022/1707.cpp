#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2505;
vector<int> graph[MAXN];
int n, m;

int findGirth() {
    int minCycle = INT_MAX;
    
    for (int start = 1; start <= n; start++) {
        vector<int> dist(n+1, INT_MAX);
        vector<int> parent(n+1, -1);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            for (int neighbor : graph[curr]) {
                if (dist[neighbor] == INT_MAX) {
                    dist[neighbor] = dist[curr] + 1;
                    parent[neighbor] = curr;
                    q.push(neighbor);
                }
                else if (parent[curr] != neighbor && parent[neighbor] != curr) {
                    int cycleLength = dist[curr] + dist[neighbor] + 1;
                    minCycle = min(minCycle, cycleLength);
                }
            }
        }
    }
    
    return minCycle == INT_MAX ? -1 : minCycle;
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    cout << findGirth() << endl;
    
    return 0;
}