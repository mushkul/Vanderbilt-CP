#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=505,INF=1000000000;
vector<int> edges[MAXN];
int capacity[MAXN][MAXN],from[MAXN],N,M;

int bfs(){
     fill(from,from+N+1,-1);
     from[1]=0;
     queue<int> Q; Q.push(1);
     while(!Q.empty()){
           int cur=Q.front(); Q.pop();
           for(auto x:edges[cur]){
                  if(from[x]==-1&&capacity[cur][x]>0){
                       from[x]=cur;
                       Q.push(x);
                  }
           }
     }
     return from[N]!=-1;
}
int main(){
     ios::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
     cin>>N>>M;
     for(int i=1;i<=M;++i){
           int a,b,c;
           cin>>a>>b>>c;
           edges[a].push_back(b);
           edges[b].push_back(a);
           capacity[a][b]+=c;
     }
     ll mf=0;
     while(bfs()){
           ll mf_cur=INF;
           for(int cur=N;cur!=1;cur=from[cur])
              mf_cur=min(mf_cur,(ll)capacity[from[cur]][cur]);

           mf+=mf_cur;

           for(int cur=N;cur!=1;cur=from[cur]){
              capacity[from[cur]][cur]-=mf_cur;
              capacity[cur][from[cur]] += mf_cur;
           }
     }
     cout<<mf;
}