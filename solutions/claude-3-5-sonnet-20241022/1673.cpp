#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e17;

struct Edge {
    int from, to;
    ll weight;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
        edges[i].weight *= -1;
    }

    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    
    // Run n-1 relaxations for shortest path
    for(int i = 1; i < n; i++) {
        for(auto e : edges) {
            if(dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
            }
        }
    }

    // Check for negative cycle reachable from node 1 to n 
    vector<bool> neg_cycle(n+1);
    for(int i = 0; i < n; i++) {
        for(auto e : edges) {
            if(dist[e.from] != INF && dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = -INF;
                neg_cycle[e.to] = true;
            }
            if(neg_cycle[e.from]) {
                neg_cycle[e.to] = true;
            }
        }
    }

    if(neg_cycle[n]) {
        cout << -1;
    } else {
        cout << -dist[n];
    }
    
    return 0;
}