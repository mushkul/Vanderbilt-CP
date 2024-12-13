#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll powmod(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    ll ans = 0;
    for (int d = 1; d <= n; d++) {
        if (n % d == 0) {
            ans += powmod(m, d);
            ans %= MOD;
        }
    }
    
    ans = (ans * powmod(n, MOD - 2)) % MOD;
    
    cout << ans << endl;
    
    return 0;
}