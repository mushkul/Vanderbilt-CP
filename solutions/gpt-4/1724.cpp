#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n,m,k;
   cin>>n>>m>>k;
   vector<pair<int,int> > g[n+1];
   int a,b,c;
   for(int i=1;i<=m;i++){
      cin>>a>>b>>c;
      g[a].push_back({b,c});
   }
   int dp[n+1][k+1];
   for(int i=1;i<=n;i++)
       for(int j=0;j<=k;j++)
          dp[i][j]=inf;
   priority_queue<pair<int,pair<int,int> > > pq;
   pq.push({0,{1,0}});
   dp[1][0]=0;
   while(!pq.empty()){
       auto u=pq.top();
       pq.pop();
       int v=u.second.first;
       int l=u.second.second;
       if(dp[v][l]<-u.first)
          continue;
       if(l==k)
          continue;
       for(auto i:g[v]){
           if(dp[i.first][l+1]>u.first-i.second){
              pq.push({u.first-i.second,{i.first,l+1}});
              dp[i.first][l+1]=u.first-i.second;
           }
       }
   }
   int ans=inf;
   for(int i=1;i<=k;i++)
       ans=min(ans,-dp[n][i]);
   if(ans==inf)
       cout<<-1<<"\n";
   else
       cout<<ans<<"\n";
}