#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

vector<int> adj[MAXN + 1];
bool visited[MAXN + 1];
int component_size;

void dfs(int node) {
    visited[node] = true;
    component_size++;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> component_sizes;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            component_size = 0;
            dfs(i);
            component_sizes.push_back(component_size);
        }
    }
    
    bitset<MAXN + 1> possible;
    possible[0] = 1;
    
    for (int size : component_sizes) {
        possible |= (possible << size);
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << possible[i];
    }
    
    cout << endl;
    
    return 0;
}