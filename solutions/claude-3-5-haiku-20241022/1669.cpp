#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
bool visited[MAXN];
int parent[MAXN];
vector<int> cycle;

bool dfs(int node, int prev, int start) {
    visited[node] = true;
    parent[node] = prev;
    
    for (int neighbor : graph[node]) {
        if (neighbor == prev) continue;
        
        if (visited[neighbor]) {
            int current = node;
            while (current != neighbor) {
                cycle.push_back(current);
                current = parent[current];
            }
            cycle.push_back(neighbor);
            cycle.push_back(node);
            return true;
        }
        
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, start)) 
                return true;
        }
    }
    
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
        graph[b].push_back(a);
    }
    
    memset(visited, false, sizeof(visited));
    
    bool found = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, 0, i)) {
                found = true;
                break;
            }
        }
    }
    
    if (!found) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << cycle.size() << endl;
        for (int city : cycle) {
            cout << city << " ";
        }
        cout << endl;
    }
    
    return 0;
}