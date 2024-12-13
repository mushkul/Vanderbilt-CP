#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> To[200010];
const int mod=1e9+7;
int n;

int dfs(int x,int f){
    vector<int> o;
    for(int i=0;i<To[x].size();i++)
    if(To[x][i]!=f){
        int pos=dfs(To[x][i],x);
        o.push_back(pos);
    }
    sort(o.begin(),o.end());
    ll hash=1;
    for(int i=0;i<o.size();i++)
    {
        ll hashi=o[i]*o[i]*o[i];
        hashi%=mod;
        hash*=hashi;
        hash%=mod;
    }
    return hash;
}
void solve(){
    int i,u,v;
    for(i=1;i<=n*2;i++)
        To[i].clear();
    for(i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        To[u].push_back(v+n);
        To[v+n].push_back(u);
    }
    for(i=n+1;i<2*n;i++){
        scanf("%d%d",&u,&v);
        To[u+n].push_back(v);
        To[v].push_back(u+n);
    }
    printf(dfs(1,0)==dfs(n+1,0)?"YES\n":"NO\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        solve();
    }
}