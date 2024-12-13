#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 50000;
vector<int> graph[MAXN + 1];
vector<int> transposed_graph[MAXN + 1];
bool visited[MAXN + 1];
int component[MAXN + 1];
vector<int> order;
vector<int> components;
int component_counter;

void dfs1(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor);
        }
    }
    order.push_back(node);
}

void dfs2(int node) {
    visited[node] = true;
    component[node] = component_counter;
    for (int neighbor : transposed_graph[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor);
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        transposed_graph[b].push_back(a);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    
    fill(visited, visited + n + 1, false);
    component_counter = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        int node = order[i];
        if (!visited[node]) {
            ++component_counter;
            dfs2(node);
        }
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (component[a] == component[b]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}