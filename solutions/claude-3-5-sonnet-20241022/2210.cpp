#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int MOD = 1e9 + 7;
 
ll power(ll x, ll y, ll m) {
    ll res = 1;
    x %= m;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        y >>= 1;
    }
    return res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    ll total = n * n;
    ll result;
    
    if (n % 2 == 0) {
        result = power(2, (total + 4) / 4, MOD);
    } else {
        result = power(2, (total + 3) / 4, MOD);
    }
    
    cout << result << '\n';
    
    return 0;
}