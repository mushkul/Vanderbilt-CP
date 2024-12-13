#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int,int>> adj[MAXN];
vector<bool> used;
bool impossible = false;

void dfs(int v, vector<int>& outdeg, vector<pair<int,int>>& res) {
    while(!adj[v].empty()) {
        auto [u, idx] = adj[v].back();
        adj[v].pop_back();
        
        if(used[idx]) continue;
        used[idx] = true;
        
        if(outdeg[v] % 2 == 0) {
            outdeg[u]++;
            res.push_back({u, v});
        } else {
            outdeg[v]++;
            res.push_back({v, u});
        }
        
        dfs(u, outdeg, res);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    used.resize(m);
    vector<int> outdeg(n+1);
    vector<pair<int,int>> edges;
    
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        edges.push_back({a, b});
    }
    
    vector<pair<int,int>> res;
    for(int i = 1; i <= n; i++) {
        dfs(i, outdeg, res);
    }
    
    for(int i = 1; i <= n; i++) {
        if(outdeg[i] % 2) impossible = true;
    }
    
    if(impossible || (int)res.size() != m) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    for(auto [a, b] : res) {
        cout << a << " " << b << "\n";
    }
    
    return 0;
}