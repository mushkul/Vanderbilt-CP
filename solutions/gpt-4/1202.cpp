#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define inf 1LL<<60
vector<pair<int,int>> adj[100005];
ll dist[100005];
ll cnt[100005];
ll minflight[100005];
ll maxflight[100005];
int n;
void dijkstra() {
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,1});
    dist[1]=0;
    cnt[1]=1;
    while(!pq.empty()) {
        int curr=pq.top().second;
        ll curr_d=pq.top().first;
        pq.pop();
        if(curr_d!=dist[curr])
            continue;
        for(pair<int,int> e: adj[curr]) {
            int next=e.first;
            ll cost=e.second;
            if(dist[next] > curr_d+cost)  {
                dist[next]=curr_d+cost;
                cnt[next]=cnt[curr];
                minflight[next]=minflight[curr]+1;
                maxflight[next]=maxflight[curr]+1;
                pq.push({dist[next],next});
            } else if(dist[next] == curr_d+cost) {
                cnt[next]=(cnt[next] + cnt[curr])%MOD;
                minflight[next]=min(minflight[next],minflight[curr]+1);
                maxflight[next]=max(maxflight[next],maxflight[curr]+1);
            }
        }
    }
}
int main() {
    int m;
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    for(int i=1; i<=n; ++i) {
        dist[i]=inf;
        minflight[i]=MOD;
    }
    dijkstra();
    cout << dist[n] << " " << cnt[n] << " "<< minflight[n] << " "<< maxflight[n] << "\n";
    return 0;
}