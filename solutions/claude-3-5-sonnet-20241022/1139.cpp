#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 200005;
vector<int> adj[MAXN];
long long col[MAXN];
int ans[MAXN];
set<long long> s[MAXN];
 
void dfs(int u, int p) {
    s[u].insert(col[u]);
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        if(s[v].size() > s[u].size()) {
            swap(s[u], s[v]);
        }
        for(auto x : s[v]) {
            s[u].insert(x);
        }
    }
    ans[u] = s[u].size();
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);
    
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}