#include <bits/stdc++.h>
#define mx 5005
#define mod 1000000007
#define ll long long
using namespace std;

ll fac[mx], ifac[mx], cnt[26];
ll power(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll nCr(ll n, ll r) {
    if(n < r || n < 0 || r < 0)
        return 0;
    return fac[n] * ifac[r] % mod * ifac[n - r] % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fac[0] = ifac[0] = 1;
    for(int i = 1; i < mx; i++) {
        fac[i] = fac[i - 1] * i % mod;
        ifac[i] = power(fac[i], mod - 2, mod);
    }
    string s;
    cin >> s;
    for(auto c: s) {
        cnt[c - 'a']++;
    }
    int n = s.size();
    ll total = fac[n];
    for(int i = 0; i < 26; i++) {
        total = total * ifac[cnt[i]] % mod;
    }
    for(int i = 1; i <= n; i++) {
        ll ways = fac[n] * ifac[n - i] % mod;
        for(int j = 0; j < 26; j++) {
            if(cnt[j] >= i) {
                ways = ways * nCr(cnt[j], i) % mod * ifac[cnt[j] - i] % mod;
            } else {
                ways = 0;
            }
        }
        if(i & 1) {
            total = (total - ways + mod) % mod;
        } else {
            total = (total + ways) % mod;
        }
    }
    cout << total << '\n';
    return 0;
}