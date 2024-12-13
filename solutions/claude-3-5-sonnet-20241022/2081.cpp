#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
vector<int> adj[MAXN];
ll k1, k2;
ll ans = 0;

int dfs(int u, int p, int d) {
    vector<int> paths = {1};
    
    for(int v : adj[u]) {
        if(v != p) {
            vector<int> child = {0};
            int sub = dfs(v, u, d+1);
            for(int i = 0; i < sub; i++)
                child.push_back(0);
                
            for(int i = 0; i < child.size(); i++) 
                child[i+1] = paths[i];
                
            paths = child;
        }
    }
    
    int sz = paths.size();
    
    for(int v : adj[u]) {
        if(v != p) {
            vector<int> child = {0};
            int sub = dfs(v, u, d+1);
            
            for(int i = 0; i < sub; i++) 
                child.push_back(0);
            
            vector<int> new_paths = paths;
            
            for(int i = 0; i < sz; i++) {
                for(int j = 0; j < child.size(); j++) {
                    if(i + j + 2 >= k1 && i + j + 2 <= k2)
                        ans += 1LL * paths[i] * child[j+1];
                }
            }
            
            for(int i = 0; i < child.size(); i++)
                new_paths[i] += child[i];
                
            paths = new_paths;
        }
    }
    
    return paths.size()-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n >> k1 >> k2;
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0, 0);
    cout << ans << "\n";
    
    return 0;
}