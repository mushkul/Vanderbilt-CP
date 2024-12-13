#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

void multiply(vector<vector<ll>>& a, vector<vector<ll>>& b, int n) {
    vector<vector<ll>> temp(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[i][j] = 0;
            for(int k = 0; k < n; k++) {
                temp[i][j] = (temp[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }
    a = temp;
}

void power(vector<vector<ll>>& adj, ll k, int n) {
    vector<vector<ll>> res(n, vector<ll>(n));
    for(int i = 0; i < n; i++) res[i][i] = 1;
    
    while(k > 0) {
        if(k & 1) multiply(res, adj, n);
        multiply(adj, adj, n);
        k >>= 1;
    }
    adj = res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<vector<ll>> adj(n, vector<ll>(n, 0));
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a][b]++;
    }
    
    power(adj, k, n);
    cout << adj[0][n-1] << "\n";
    
    return 0;
}