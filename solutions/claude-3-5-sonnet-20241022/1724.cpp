#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main() {
    int n, m, a, b, c;
    ll k;
    cin >> n >> m >> k;
    
    vector<vector<ll>> adj(n, vector<ll>(n, INF));
    vector<vector<ll>> res(n, vector<ll>(n, INF));
    
    for(int i = 0; i < n; i++)
        adj[i][i] = res[i][i] = 0;
        
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        adj[a][b] = min(adj[a][b], (ll)c);
    }
    
    vector<vector<ll>> temp(n, vector<ll>(n));
    
    while(k > 0) {
        if(k & 1) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    temp[i][j] = INF;
                    for(int l = 0; l < n; l++) {
                        if(res[i][l] != INF && adj[l][j] != INF)
                            temp[i][j] = min(temp[i][j], res[i][l] + adj[l][j]);
                    }
                }
            }
            res = temp;
        }
        
        vector<vector<ll>> temp2(n, vector<ll>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                temp2[i][j] = INF;
                for(int l = 0; l < n; l++) {
                    if(adj[i][l] != INF && adj[l][j] != INF)
                        temp2[i][j] = min(temp2[i][j], adj[i][l] + adj[l][j]);
                }
            }
        }
        adj = temp2;
        k >>= 1;
    }
    
    cout << (res[0][n-1] == INF ? -1 : res[0][n-1]) << endl;
    
    return 0;
}