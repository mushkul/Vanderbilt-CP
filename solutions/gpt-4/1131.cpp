#include<bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int n, a, b, maxd = 0, maxi = 1;
bool visited[200005];
int depth[200005];

void dfs(int s, int d){
    visited[s] = true;
    depth[s] = d;
    if(d > maxd){
        maxd = d;
        maxi = s;
    }
    for(int i = 0; i < adj[s].size(); ++i){
        if(!visited[adj[s][i]]){
            dfs(adj[s][i], d+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n-1; ++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    fill_n(visited,n+1,false);
    maxd = 0;
    dfs(maxi,0);
    cout << maxd;
    return 0;
}