c++
#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;


int main(){
    vector<pair<int, int> > adj[100005];
    vector<ll> dist[100005];
    vector<bool> done[100005];
    int n, m, k, a, b, c;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        adj[a].push_back(make_pair(b, c));
    }
    
    priority_queue<pair<ll, ii>, vector<pair<ll, ii> >, greater<pair<ll, ii> > > pq;
    pq.push(make_pair(0, make_pair(0, 0)));
    while(!pq.empty()){
        ll d = pq.top().first;
        int v = pq.top().second.first, t = pq.top().second.second;
        pq.pop();
        if(done[v].size() > t) continue;
        done[v].push_back(true);
        dist[v].push_back(d);
        for(auto edge : adj[v]){
            if(done[edge.first].size() <= t){
                pq.push(make_pair(d + edge.second, make_pair(edge.first, t+1)));
            }
        }
    }
    for(int i = 0; i < k; i++) printf("%lld\n", dist[n - 1][i]);
}