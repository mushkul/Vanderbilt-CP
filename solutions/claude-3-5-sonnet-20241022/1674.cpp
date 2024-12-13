#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subordinates;

int dfs(int node) {
    int count = 0;
    for(int child : adj[node]) {
        count += 1 + dfs(child);
    }
    subordinates[node] = count;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    adj.resize(n+1);
    subordinates.resize(n+1);
    
    for(int i = 2; i <= n; i++) {
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }
    
    dfs(1);
    
    for(int i = 1; i <= n; i++) {
        cout << subordinates[i] << " ";
    }
    
    return 0;
}