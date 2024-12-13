#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1);
    vector<pair<int, int>> edges(m);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        edges[i] = {a, b};
    }
    
    vector<int> outdegree(n + 1, 0);
    
    for (auto& edge : edges) {
        int u = edge.first, v = edge.second;
        
        if (outdegree[u] % 2 == 0) {
            cout << u << " " << v << endl;
            outdegree[u]++;
            outdegree[v]++;
        } else {
            cout << v << " " << u << endl;
            outdegree[v]++;
            outdegree[u]++;
        }
    }
}