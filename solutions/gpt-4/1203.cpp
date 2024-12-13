#include<bits/stdc++.h>
using namespace std;
#define INF 1000000000000000000
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<pair<int,ll>> adj[n+1];
    ll cost[n+1];
    int parent[n+1];
    for(int i=0; i<=n; i++)
        cost[i] = INF;

    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0,1});
    cost[1] = 0;
    parent[1] = -1;

    while (!pq.empty()) {
        int a = pq.top().second; pq.pop();
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;
            if (cost[a]+w < cost[b]) {
                cost[b] = cost[a]+w;
                parent[b] = a;
                pq.push({cost[b], b});
            }
        }
    }

    int x = n;
    vector<int> path;
    for(; x!=-1; x = parent[x])
        path.push_back(x);
    reverse(path.begin(), path.end());

    cout<<path.size()<<"\n";
    for(int x: path)
        cout<<x<<" ";

    return 0;
}