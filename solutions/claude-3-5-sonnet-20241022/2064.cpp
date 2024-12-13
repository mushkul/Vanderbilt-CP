#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const int MOD = 1e9 + 7;
 
ll modPow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
 
ll modInverse(ll a, ll m) {
    return modPow(a, m-2, m);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    n /= 2;
    
    ll num = 1;
    for (ll i = 0; i < n; i++) {
        num = (num * (4*i + 2)) % MOD;
    }
    
    ll den = 1;
    for (ll i = 0; i < n + 1; i++) {
        den = (den * i) % MOD;
        if (den == 0) den = 1;
    }
    
    ll result = (num * modInverse(den, MOD)) % MOD;
    cout << result << endl;
    
    return 0;
}