#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int MOD = 1e9 + 7;
 
ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
ll modInverse(ll n) {
    return power(n, MOD-2);
}
 
ll nCr(ll n, ll r) {
    if (r > n) return 0;
    ll res = 1;
    for (ll i = 0; i < r; i++) {
        res = (res * (n - i)) % MOD;
        res = (res * modInverse(i + 1)) % MOD;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    cout << nCr(n + m - 1, n - 1);
    
    return 0;
}