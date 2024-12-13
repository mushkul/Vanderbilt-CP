#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;

ll power(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << power(a, b) << "\n";
    }
    
    return 0;
}