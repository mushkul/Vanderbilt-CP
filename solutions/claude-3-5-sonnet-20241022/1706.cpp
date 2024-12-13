#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int MAX_N = 100005;
vector<int> adj[MAX_N];
bool visited[MAX_N];
int comp_size;
 
void dfs(int u) {
    visited[u] = true;
    comp_size++;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    // Build adjacency list
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    // Find connected components
    vector<int> components;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            comp_size = 0;
            dfs(i);
            components.push_back(comp_size);
        }
    }
    
    // Calculate possible sums using subset sum
    vector<bool> possible(n + 1);
    possible[0] = true;
    
    for(int size : components) {
        for(int sum = n; sum >= 0; sum--) {
            if(possible[sum]) {
                possible[sum + size] = true;
            }
        }
    }
    
    // Output answer
    for(int i = 0; i <= n; i++) {
        cout << possible[i];
    }
    cout << "\n";
    
    return 0;
}