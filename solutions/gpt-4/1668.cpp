#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100001];
int vis[100001], col[100001];

bool dfs(int node, int color){
    vis[node] = 1;
    col[node] = color;
    for(int child : adj[node]){
        if(vis[child] == 0){
            if(dfs(child, color^1) == false)
                return false;
        }
        else{
            if(col[node] == col[child])
                return false;
        }
    }
    return true;
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(vis[i] == 0){
            if(dfs(i, 1) == false){
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << col[i]+1 << " ";
    }
    return 0;
}