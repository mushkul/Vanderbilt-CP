#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll modpow(ll base, ll exp, ll modulus) {
    base %= modulus;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

ll modinv(ll a, ll m) {
    return modpow(a, m-2, m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    ll num = 1;
    ll sum = 1; 
    ll prod = 1;
    ll prod_pow = 1;
    
    for(int i = 0; i < n; i++) {
        ll p, k;
        cin >> p >> k;
        
        ll curr_num = (k + 1) % MOD;
        num = (num * curr_num) % MOD;
        
        ll p_pow = modpow(p, k+1, MOD);
        ll denom = (p - 1) % MOD;
        ll curr_sum = ((p_pow - 1 + MOD) % MOD * modinv(denom, MOD)) % MOD;
        sum = (sum * curr_sum) % MOD;
        
        ll half = (k * (k + 1) / 2) % (MOD - 1);
        prod_pow = (prod_pow * (k + 1)) % (MOD - 1);
        
        prod = modpow(prod, k+1, MOD);
        prod = (prod * modpow(p, half, MOD)) % MOD;
    }
    
    cout << num << " " << sum << " " << prod << "\n";
    
    return 0;
}