#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAXN = 1e6+5;

ll fact[MAXN];
ll inv[MAXN];

ll power(ll x, ll y) {
    ll res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    inv[MAXN-1] = power(fact[MAXN-1], MOD-2);
    for(int i = MAXN-2; i >= 0; i--) {
        inv[i] = (inv[i+1] * (i+1)) % MOD;
    }
}

ll nCr(ll n, ll r) {
    if(r < 0 || r > n) return 0;
    return (((fact[n] * inv[r]) % MOD) * inv[n-r]) % MOD;
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    precompute();
    
    int n;
    cin >> n;
    while(n--) {
        ll a, b;
        cin >> a >> b;
        cout << nCr(a, b) << '\n';
    }
    return 0;
}