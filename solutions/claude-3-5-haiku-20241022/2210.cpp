#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

ll power(ll x, ll y) {
    ll res = 1;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % MOD;
        y >>= 1;
        x = (x * x) % MOD;
    }
    return res;
}

ll solve(int n) {
    if (n == 1) return 2;
    ll totalConfigs = power(2, n * n);
    ll symmetricConfigs = 0;
    
    // Rotation symmetries
    if (n % 2 == 0) {
        symmetricConfigs += power(2, n * n / 4) * 4;
        symmetricConfigs += power(2, n * n / 4) * 2;
        symmetricConfigs += power(2, n * n / 2);
    } else {
        symmetricConfigs += power(2, (n * n + 1) / 2);
        symmetricConfigs += power(2, (n * n - 1) / 2) * 4;
    }
    
    // Reflection symmetries
    if (n % 2 == 0) {
        symmetricConfigs += power(2, n * n / 4) * 4;
        symmetricConfigs += power(2, n * n / 2) * 2;
        symmetricConfigs += power(2, n * n / 4) * 4;
    } else {
        symmetricConfigs += power(2, (n * n + 1) / 2);
        symmetricConfigs += power(2, (n * n - 1) / 2) * 4;
        symmetricConfigs += power(2, (n * n - 1) / 2) * 4;
    }
    
    symmetricConfigs %= MOD;
    
    ll result = (totalConfigs - symmetricConfigs + MOD) % MOD;
    result = (result / 8);
    
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}