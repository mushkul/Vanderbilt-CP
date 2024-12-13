#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll power(ll x, ll y) {
    ll res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;  
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t, x, y;
    cin >> t;
    while(t--) {
        cin >> x >> y;
        cout << power(x, y) << "\n";
    }
    return 0;
}