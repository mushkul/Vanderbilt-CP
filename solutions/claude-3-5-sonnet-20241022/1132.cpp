#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+5;
vector<int> adj[maxN];
int dist[maxN];
int depth[maxN];

void dfs(int u, int p, vector<int>& d){
    for(int v : adj[u]){
        if(v == p) continue;
        d[v] = d[u] + 1;
        dfs(v, u, d);
    }
}

int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> d1(n+1);
    dfs(1, 0, d1);
    
    int maxNode = 1;
    for(int i=1; i<=n; i++){
        if(d1[i] > d1[maxNode]){
            maxNode = i;
        }
    }
    
    vector<int> da(n+1);
    dfs(maxNode, 0, da);
    
    maxNode = 1;
    for(int i=1; i<=n; i++){
        if(da[i] > da[maxNode]){
            maxNode = i;
        }
    }
    
    vector<int> db(n+1);
    dfs(maxNode, 0, db);
    
    for(int i=1; i<=n; i++){
        cout << max(da[i], db[i]) << " ";
    }
    
    return 0;
}