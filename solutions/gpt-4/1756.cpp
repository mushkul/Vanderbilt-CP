c++
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> order;
vector<bool> visited;
vector<pair<int, int>> edges;

void dfs(int node) {
    visited[node] = true;
    for(auto i : adj[node]) {
        if(!visited[i]) dfs(i);
    }
    order.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	
    int n, m;
    cin>>n>>m;
    adj.resize(n+1);
    visited.resize(n+1);

    while(m--) {
        int a, b;
        cin>>a>>b;
        edges.push_back({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++) {
        if(!visited[i]) dfs(i); 
    }

    vector<int> pos(n+1);
    for(int i=0; i<n; ++i) {
        pos[order[i]] = i; 
    }

    for(auto i : edges) {
        if(pos[i.first] < pos[i.second]) cout<<i.first<<" "<<i.second<<"\n";
        else cout<<i.second<<" "<<i.first<<"\n";
    }
	
    return 0;
}