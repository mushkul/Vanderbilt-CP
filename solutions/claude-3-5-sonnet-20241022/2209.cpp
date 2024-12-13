#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
const int MOD = 1e9 + 7;
 
ll power(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
 
ll modInverse(ll n, ll p) {
    return power(n, p - 2, p);
}
 
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    
    ll result = 0;
    for(ll d = 1; d <= n; d++) {
        if(n % d == 0) {
            ll temp = power(m, d, MOD);
            temp = (temp * n/d) % MOD;
            result = (result + temp) % MOD;
        }
    }
    
    result = (result * modInverse(n, MOD)) % MOD;
    cout << result << "\n";
    
    return 0;
}