#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+5;
vector<int> adj[MAX_N];
int n;
int subtree[MAX_N];

int dfs(int node, int parent) {
    subtree[node] = 1;
    for(int child : adj[node]) {
        if(child != parent) {
            subtree[node] += dfs(child, node);
        }
    }
    return subtree[node];
}

int find_centroid(int node, int parent) {
    for(int child : adj[node]) {
        if(child != parent && subtree[child] > n/2) {
            return find_centroid(child, node);
        }
    }
    return node;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);
    cout << find_centroid(1, 0) << "\n";
    
    return 0;
}