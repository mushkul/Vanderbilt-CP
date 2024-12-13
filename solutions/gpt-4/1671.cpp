#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e5;
const ll INF=1e18;

int n, m;
vector<pair<int,ll>> adj[MAXN+10];
ll dist[MAXN+10];
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;

int main() {
    scanf("%d %d",&n,&m);
    for(int i=1; i<=m; i++) {
        int a, b;
        ll w;
        scanf("%d %d %lld",&a,&b,&w);
        adj[a].push_back({b,w});
    }
    fill(dist,dist+n+1,INF);
    dist[1]=0;
    q.push({0,1});
    while(!q.empty()) {
	    ll d = q.top().first;
        int node = q.top().second;
        q.pop();
        if(d != dist[node]) continue;
        for(auto next : adj[node]) {
            if(dist[next.first] > d+next.second) {
                dist[next.first] = d + next.second;
                q.push({dist[next.first],next.first});
            }
        }
    }
    for(int i=1; i<=n; i++) printf("%lld ",dist[i]);
    return 0;
}