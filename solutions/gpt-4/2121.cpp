#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define pb push_back
#define F first
#define S second
#define INF 1e18
const ll mxN = 510;
vector<vector<pll>> adj;
ll d[mxN][110];
ll n,m,k;

void dijkstra(){
    priority_queue<pair<ll, pair<ll, ll>>> q;
    for(ll i=0;i<mxN;i++)
	for(ll j=0;j<110;j++)d[i][j]=INF;
    d[1][0] = 0;
    q.push({0,{1,0}});
    while(!q.empty()){
	ll du=-q.top().F,node=q.top().S.F,parcels=q.top().S.S;
	q.pop();
	if(du!=d[node][parcels])continue;
	for(auto x:adj[node]){
	    ll tonode=x.F,cost=x.S.F,capacity=x.S.S;
	    ll need=max(0LL,parcels-capacity);
	    if(du+need*cost<d[tonode][need]){
		d[tonode][need]=du+need*cost;
		q.push({-d[tonode][need],{tonode,need}});
	    }
	}
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    adj.resize(n+1);
    while(m--){
    	ll a, b, r, c;
    	cin>>a>>b>>r>>c;
    	adj[a].push_back({b, {c,r}});
    }
    dijkstra();
    ll ans=INF;
    for(ll i=0;i<=k;i++) ans=min(ans,d[n][i]);
    if(ans==INF) cout<<"-1\n";
    else cout<<ans<<"\n";
}