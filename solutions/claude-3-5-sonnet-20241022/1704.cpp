#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<int> adj[MAX_N];
int n;
vector<int> leaves;

void dfs(int u, int p) {
    bool isLeaf = true;
    for(int v : adj[u]) {
        if(v != p) {
            dfs(v, u);
            isLeaf = false;
        }
    }
    if(isLeaf && u != 1) {
        leaves.push_back(u);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);
    
    int k = (leaves.size() + 1) / 2;
    cout << k << "\n";
    
    for(int i = 0; i < k; i++) {
        cout << leaves[i] << " " << leaves[(i+k)%leaves.size()] << "\n";
    }
    
    return 0;
}