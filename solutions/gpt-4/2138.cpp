#include<bits/stdc++.h>
using namespace std;
const int MAXN=50010;
vector <int> edges[MAXN];
bool visited[MAXN];
int dp[MAXN];
void dfs(int node){
    visited[node]=true;
    for(auto it:edges[node]){
        if(!visited[it]) dfs(it);
        dp[node]+=dp[it]+1;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
    }
    for(int i=n;i>=1;i--){
        if(!visited[i]) dfs(i);
    }
    for(int i=1;i<=n;i++){
        cout<<dp[i]+1<<" ";
    }
    return 0;
}