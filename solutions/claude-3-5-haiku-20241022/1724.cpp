#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], (ll)c);
    }
    
    vector<vector<ll>> curr = dist;
    
    for (int t = 1; t < k; t++) {
        vector<vector<ll>> next(n+1, vector<ll>(n+1, INF));
        
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                for (int c = 1; c <= n; c++) {
                    if (curr[a][c] != INF && dist[c][b] != INF) {
                        next[a][b] = min(next[a][b], curr[a][c] + dist[c][b]);
                    }
                }
            }
        }
        
        curr = next;
    }
    
    ll ans = curr[1][n];
    cout << (ans == INF ? -1 : ans) << endl;
    
    return 0;
}