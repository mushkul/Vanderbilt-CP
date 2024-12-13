#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 100000;
vector<int> graph[MAXN + 1];
int visited[MAXN + 1], parent[MAXN + 1];
int cycle_start, cycle_end;
stack<int> s;

bool dfs(int v) {
    visited[v] = 1;
    s.push(v);
    for (int u : graph[v]) {
        if (!visited[u]) {
            parent[u] = v;
            if (dfs(u)) return true;
        } else if (visited[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    visited[v] = 2;
    s.pop();
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    cycle_start = -1;
    for (int v = 1; v <= n; ++v) {
        if (!visited[v]) {
            if (dfs(v)) break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        while (!s.empty() && s.top() != cycle_start) {
            cycle.push_back(s.top());
            s.pop();
        }
        cycle.push_back(cycle_start);
        
        reverse(cycle.begin(), cycle.end());
        int idx = 0;
        while (idx < cycle.size() && cycle[idx] != cycle_end) ++idx;
        
        cout << cycle.size() - idx + 1 << "\n";
        for (int i = idx; i < cycle.size(); ++i) {
            cout << cycle[i] << " ";
        }
        cout << cycle[idx] << "\n";
    }
    
    return 0;
}