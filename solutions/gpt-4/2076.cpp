#include<bits/stdc++.h>
using namespace std;

const int MX=1e5+5; 
vector<int> a[MX],res; int n,m,lo[MX],num[MX],par[MX];
int cou=0; 
bool vis[MX]; 

void dfs(int u) {
 num[u]=lo[u]=++cou; vis[u]=true;
 for(auto v:a[u]) {
  if(!vis[v]) {
   par[v]=u;
   dfs(v);
   lo[u] = min(lo[u],lo[v]);
   if(lo[v]>=num[u]) res.push_back(u);
  } else if(v!=par[u]) lo[u] = min(lo[u],num[v]);
 }
}

int main(){
 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 cin>>n>>m;
 for(int i=1;i<=m;++i) {
  int u,v; cin>>u>>v; a[u].push_back(v); a[v].push_back(u);
 }
 par[1]=-1;
 dfs(1);
 sort(res.begin(),res.end());
 res.erase(unique(res.begin(),res.end()),res.end());
 cout<<res.size()<<'\n';
 for(auto it : res) cout<<it<<'\n';
 }