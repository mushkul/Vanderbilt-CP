#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,low[100005],num[100005],dem,ans[100005],cnt,bac[100005];
vector<int> a[100005];
int dfs(int u,int p){
    low[u]=num[u]=++dem;
    bac[u]=1;
    for (int v:a[u]){
        if (v==p) continue;
        if (!num[v]){
            bac[u]+=dfs(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]>=num[u]) ans[u]=1;
        } else low[u]=min(low[u],num[v]);
    }
    return bac[u];
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    a[0].push_back(1);
    for (int i=1;i<=m;i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(0,-1);
    cnt=0;
    for (int i=0;i<=n;i++)
        if (ans[i]) cnt++;
    cout<<cnt<<'\n';
    for (int i=1;i<=n;i++)
        if (ans[i]) cout<<i<<' ';
}