#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
vector<bool> visited;
vector<bool> assignment;
vector<int> comp;
int comp_cnt;

void dfs(int u) {
    visited[u] = true;
    comp[u] = comp_cnt;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

bool dfs2(int u) {
    visited[u] = true;
    comp[u] = comp_cnt;
    for (int v : adj[u]) {
        if (!visited[v]) {
            assignment[v] = !assignment[u];
            if (!dfs2(v)) return false;
        }
        else if (assignment[v] == assignment[u]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int,int>> clauses;
    vector<bool> is_positive;
    
    for (int i = 0; i < n; i++) {
        char type1, type2;
        int x, y;
        cin >> type1 >> x >> type2 >> y;
        
        bool pos1 = type1 == '+';
        bool pos2 = type2 == '+';
        
        x--; y--; // 0-based indexing
        
        clauses.push_back({x, y});
        is_positive.push_back(pos1);
        is_positive.push_back(pos2);
    }
    
    for (int i = 0; i < n; i++) {
        int x = clauses[i].first;
        int y = clauses[i].second;
        bool pos1 = is_positive[2*i];
        bool pos2 = is_positive[2*i+1];
        
        int node1 = 2*x + (pos1 ? 0 : 1);
        int node2 = 2*y + (pos2 ? 0 : 1);
        int not_node1 = 2*x + (pos1 ? 1 : 0);
        int not_node2 = 2*y + (pos2 ? 1 : 0);
        
        adj[not_node1].push_back(node2);
        adj[not_node2].push_back(node1);
    }
    
    visited.assign(2*m, false);
    comp.assign(2*m, -1);
    comp_cnt = 0;
    
    for (int i = 0; i < 2*m; i++) {
        if (!visited[i]) {
            dfs(i);
            comp_cnt++;
        }
    }
    
    assignment.assign(2*m, false);
    visited.assign(2*m, false);
    bool possible = true;
    
    for (int i = 0; i < 2*m; i++) {
        if (!visited[i]) {
            if (!dfs2(i)) {
                possible = false;
                break;
            }
        }
    }
    
    if (!possible) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for (int i = 0; i < m; i++) {
        cout << (assignment[2*i] ? "+" : "-");
    }
    cout << "\n";
    
    return 0;
}