#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

vector<vector<ll>> multiply(vector<vector<ll>>& a, vector<vector<ll>>& b) {
    int n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % mod) % mod;
            }
        }
    }
    return res;
}

vector<vector<ll>> power(vector<vector<ll>>& a, ll p) {
    int n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n));
    for(int i = 0; i < n; i++) res[i][i] = 1;
    
    while(p) {
        if(p & 1) res = multiply(res, a);
        a = multiply(a, a);
        p >>= 1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;
    
    vector<vector<ll>> base = {
        {1,1,1,1,1,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0}
    };
    
    vector<vector<ll>> res = power(base, n);
    cout << res[0][0] << endl;
    
    return 0;
}