#include<bits/stdc++.h>
using namespace std;
const int mxN=2e5+10;
vector<int>adj[mxN],clr[mxN];
int col[mxN],res[mxN],m[mxN],par[mxN];
void add(int node, int parent) {
    for(auto c: clr[node]) if(m[c]==0) res[parent]++;
    for(auto i: clr[node]) m[i]++;
    for(auto i: adj[node]){
        if(i==par[node]) continue;
        add(i, parent);
    }
    for(auto i: clr[node]) m[i]--;
}
void dfs(int node, int parent){
    par[node]=parent;
    for(auto i: adj[node]){
        if(i==parent) continue;
        dfs(i, node);
    }
    clr[node].push_back(col[node]);
    for(auto i: adj[node]){
        if(i==parent) continue;
        if(clr[i].size()>clr[node].size()) swap(clr[i], clr[node]);
        for(auto c: clr[i]) clr[node].push_back(c);
    }
    add(node, node);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>col[i];
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    return 0;
}