#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> adj;
vector<int> color;
stack<int> nodes;

void topological_sort(int node) {
    color[node] = 1;
    for (auto neigh : adj[node]) {
        if (color[neigh] == 0) {
            topological_sort(neigh);
        }
    }
    nodes.push(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    adj.resize(n + 1);
    color.resize(n + 1, 0);
    vector<pair<int, int>> edges;

    while (m--) {
        int a, b;
        cin >> a >> b;
        edges.emplace_back(a, b);
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) {
            topological_sort(i);
        }
    }

    vector<int> position(n + 1);
    int index = 0;
    while (!nodes.empty()) {
        position[nodes.top()] = index++;
        nodes.pop();
    }

    for (auto &[a, b] : edges) {
        if (position[a] < position[b]) {
            cout << a << " " << b << "\n";
        } else {
            cout << b << " " << a << "\n";
        }
    }
    return 0;
}