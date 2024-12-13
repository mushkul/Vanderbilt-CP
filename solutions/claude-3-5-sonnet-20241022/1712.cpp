#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const ll mod2 = mod - 1;

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        
        ll exp = binpow(b, c, mod2);
        cout << binpow(a, exp, mod) << '\n';
    }
    
    return 0;
}