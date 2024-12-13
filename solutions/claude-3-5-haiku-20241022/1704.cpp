#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
vector<int> degree;

void dfs(int node, int parent, set<int>& critical) {
    int child_count = 0;
    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;
        child_count++;
        dfs(neighbor, node, critical);
    }
    if (child_count >= 2) critical.insert(node);
}

int main() {
    int n;
    cin >> n;
    
    graph.resize(n + 1);
    degree.resize(n + 1, 0);
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    
    set<int> critical;
    dfs(1, 0, critical);
    
    vector<pair<int, int>> new_connections;
    for (int node : critical) {
        vector<int> children;
        for (int neighbor : graph[node]) {
            children.push_back(neighbor);
        }
        
        for (int i = 0; i < children.size(); i++) {
            for (int j = i + 1; j < children.size(); j++) {
                new_connections.push_back({children[i], children[j]});
            }
        }
    }
    
    cout << new_connections.size() << endl;
    for (auto& conn : new_connections) {
        cout << conn.first << " " << conn.second << endl;
    }
    
    return 0;
}