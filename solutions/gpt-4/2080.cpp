#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;

int n,k,tot;
long long ans;
int head[maxn],sz[maxn];
struct Edge{
    int nex;
    int to;
}edge[maxn<<1];

void add(int u,int v){
    edge[tot].to=v;
    edge[tot].nex=head[u];
    head[u]=tot++;
}

void dfs(int u,int fa){
    sz[u]=1;
    for(int i=head[u];i!=-1;i=edge[i].nex){
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
    }
}

void dfs(int u,int fa,int dep){
    for(int i=head[u];i!=-1;i=edge[i].nex){
        int v=edge[i].to;
        if(v==fa) continue;
        dfs(v,u,dep+1);
    }
    if(dep<k) return;
    ans+=(long long)(sz[u]);
    if(dep==k) ans+=(long long)(n-sz[fa]-1);
}

int main(){
    int u,v;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    dfs(1,0,0);
    printf("%lld\n",ans/2);
    return 0;
}