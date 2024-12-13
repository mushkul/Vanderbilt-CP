#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<pair<int,int>> adj[MAX_N];
vector<int> path;
int n, m;
vector<bool> used;

void find_path(int v) {
    while(!adj[v].empty()) {
        auto edge = adj[v].back();
        adj[v].pop_back();
        if(used[edge.second]) continue;
        used[edge.second] = true;
        find_path(edge.first);
    }
    path.push_back(v);
}

int main() {
    cin >> n >> m;
    vector<int> in_deg(n+1), out_deg(n+1);
    used.resize(m);
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        out_deg[a]++;
        in_deg[b]++;
    }
    
    // Check Euler path conditions
    bool possible = true;
    for(int i = 2; i < n; i++) {
        if(in_deg[i] != out_deg[i]) {
            possible = false;
            break;
        }
    }
    if(out_deg[1] != in_deg[1] + 1 || in_deg[n] != out_deg[n] + 1)
        possible = false;
        
    if(!possible) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    find_path(1);
    reverse(path.begin(), path.end());
    
    if(path.size() != m+1 || path[0] != 1 || path.back() != n) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    
    for(int x : path)
        cout << x << " ";
        
    return 0;
}