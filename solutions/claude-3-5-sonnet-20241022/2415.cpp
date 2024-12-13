#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
using ll = long long;
 
ll powmod(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
 
vector<vector<ll>> C;
vector<ll> fact, invfact;
 
void precompute(int n) {
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invfact[n] = powmod(fact[n], MOD-2);
    for(int i = n-1; i >= 0; i--) {
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
    }
    
    C.resize(n + 1, vector<ll>(n + 1));
    for(int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
        }
    }
}
 
ll nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    return (((fact[n] * invfact[r]) % MOD) * invfact[n-r]) % MOD;
}
 
int main() {
    int n;
    cin >> n;
    precompute(n);
    
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp[i] = 0;
        for(int j = 1; j <= i; j++) {
            ll ways = (((fact[i-1] * invfact[i-j]) % MOD) * nCr(i, j)) % MOD;
            dp[i] = (dp[i] + (ways * dp[i-j]) % MOD) % MOD;
        }
    }
    
    vector<ll> ans(n + 1);
    for(int k = 1; k <= n; k++) {
        ans[k] = 0;
        for(int i = 0; i <= n-k; i++) {
            ll sign = (i % 2 == 0) ? 1 : MOD-1;
            ll term = (((nCr(n-k, i) * dp[n-i]) % MOD) * sign) % MOD;
            ans[k] = (ans[k] + term) % MOD;
        }
    }
    
    for(int k = 1; k <= n; k++) {
        cout << ans[k] << "\n";
    }
    
    return 0;
}