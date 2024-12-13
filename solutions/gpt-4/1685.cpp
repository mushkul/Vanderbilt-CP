#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define in insert
#define mod 1000000007
#define F first
#define S second
#define INF 1e18
#define pii pair<int,int>
#define vii vector<int>
#define sz(x) (int)(x.size())
#define all(x) (x).begin(), (x).end()
#define rep(i,a,b) for(int i=a ; i<b ; i++)
#define rrep(i,b,a) for(int i=b ; i>=a ; i--)
#define revep(i,a) for(int i=0 ; i<a ; i++)
#define arr(a,n) int a[n]; rep(i,0,n) cin>>a[i]
#define arr1(a,n) int a[n+1]; rep(i,1,n+1) cin>>a[i]
#define sort0(v) sort(v.begin(), v.end())
#define sort1(v) sort(v.begin(), v.end(), greater<int>())
#define maxa(a,n) *max_element(a,a+n)
#define mina(a,n) *min_element(a,a+n)
#define fastio std::ios::sync_with_stdio(false)

void dfs(int node,vector<int> *G,bool *visited,vector<int> &Res){
    visited[node]=true;
    for(auto child:G[node]){
        if(!visited[child]){
            dfs(child,G,visited,Res);
        }
    }
    Res.pb(node);
}

int main(){
    fastio;
    int n,m;
    cin>>n>>m;
    vector<int> G[n+1];
    bool visited[n+1];
    memset(visited,0,sizeof(visited));
    rep(i,1,m+1){
        int x,y;
        cin>>x>>y;
        G[x].pb(y);
    }
    vector<int> Res;
    rep(i,1,n+1){
        if(!visited[i]){
            dfs(i,G,visited,Res);
        }
    }
    rep(i,0,n){
        visited[Res[i]]=i;
    }
    vii ans;
    rep(i,1,n){
        if(visited[Res[i]]>visited[Res[i-1]]){
            ans.pb(i);
        }
    }
    cout<<sz(ans)<<'\n';
    rep(i,0,sz(ans)){
        cout<<Res[ans[i]-1]<<" "<<Res[ans[i]]<<'\n';
    }
    return 0;
}