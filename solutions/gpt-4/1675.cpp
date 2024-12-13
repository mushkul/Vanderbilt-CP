#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=1e5+5;
vector<pair<int, int>> adj[MAXN];
int parent[MAXN];
bool visited[MAXN]{};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for(auto &edge : adj[u]) {
            if(!visited[edge.second]) {
                parent[edge.second] = u;
                pq.push(edge);
            }
        }
    }
    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        if(!parent[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        for(auto &edge : adj[i]) {
            if(edge.second == parent[i]) {
                ans += edge.first;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}