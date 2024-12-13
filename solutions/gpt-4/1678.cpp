#include<bits/stdc++.h>
using namespace std;
 
const int maxN = 1e5+7;
vector<int> G[maxN] , path(maxN,-1);
bool visited[maxN] = {false};
int n , m , s , e = -1;
 
bool dfs(int u){
  visited[u] = true;
  for(auto &it : G[u]){
    if(visited[it]){
      if(path[u]!=it){
        s = it;
        e = u;
        return true;
      }
      continue;
    }
    path[it] = u;
    if(dfs(it)) return true;
  }
  return false;
}
 
int main(){
  cin>>n>>m;
  for(int i=0;i<m;++i){
    int a,b;
    cin>>a>>b;
    G[a].push_back(b);
  }
  for(int i=1;i<=n;++i){
    if(!visited[i]){
      path[i] = -1;
      if(dfs(i)) break;
    }
  }
  if(e==-1) cout<<"IMPOSSIBLE"<<'\n';
  else{
    vector<int> ans;
    ans.push_back(s);
    for(int v=e;v!=s;v=path[v]) ans.push_back(v);
    ans.push_back(s);
    cout<<ans.size()<<'\n';
    for(auto &it:ans) cout<<it<<' ';
  }
  return 0;
}