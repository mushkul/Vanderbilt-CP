#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> used;
stack<int> path;
vector<pair<int, int>> edges;
vector<int> circuit;
int edge_count;
bool possible = true;

void eulerian_path(int start) {
    path.push(start);
    while(!path.empty()) {
        int u = path.top();
        int i;
        for(i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if(!used[u][i]) {
                used[u][i] = true;
                for(int j = 0; j < adj[v].size(); j++) {
                    if(adj[v][j] == u && !used[v][j]) {
                        used[v][j] = true;
                        break;
                    }
                }
                path.push(v);
                break;
            }
        }
        if(i == adj[u].size()) {
            circuit.push_back(u);
            path.pop();
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> degree(n + 1, 0);
    adj.resize(n + 1);
    used.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        adj[i] = vector<int>();
        used[i] = vector<bool>();
    }
    edge_count = m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        used[a].push_back(false);
        used[b].push_back(false);
        degree[a]++;
        degree[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) possible = false;
    }
    eulerian_path(1);
    if (!possible || circuit.size() != edge_count + 1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        reverse(circuit.begin(), circuit.end());
        for (int i = 0; i < circuit.size(); i++) {
            cout << circuit[i] << " ";
        }
        cout << endl;
    }
    return 0;
}