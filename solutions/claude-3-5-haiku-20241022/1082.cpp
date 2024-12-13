#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

ll sumOfDivisors(ll n) {
    ll result = 0;
    for (ll i = 1; i <= n; i++) {
        result += (n / i) * i;
        result %= MOD;
    }
    return result;
}

int main() {
    ll n;
    cin >> n;
    cout << sumOfDivisors(n) << endl;
    return 0;
}