#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

vector<pii> adj[MAXN][2];
ll dp[MAXN][2];
bool vis[MAXN][2];

int main(){

    int n, m;
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u][0].push_back({v, c});
        adj[u][1].push_back({v, c});
        adj[v][1].push_back({u, 2*c});
    }

    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>>> pq;
    pq.push({0, {1, 0}});
    memset(dp, 0x3f, sizeof(dp));
    dp[1][0] = 0;
    while(!pq.empty()){
        pair<ll, pii> cur = pq.top();
        pq.pop();
        int u = cur.second.first, state = cur.second.second;
        if(vis[u][state]) continue;
        vis[u][state] = true;
        for(pii nxt : adj[u][state]){
            int v = nxt.first, c = nxt.second;
            if(dp[v][state] > dp[u][state] + c){
                dp[v][state] = dp[u][state] + c;
                pq.push({dp[v][state], {v, state}});
            }
            if(!state && dp[v][1] > dp[u][0] + c/2){
                dp[v][1] = dp[u][state] + c/2;
                pq.push({dp[v][1], {v, 1}});
            }
        }
    }

    cout << min(dp[n][0], dp[n][1]) << "\n";

    return 0;
}