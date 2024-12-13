#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

ll sumOfDivisors(ll n) {
    ll sum = 0;
    for (ll i = 1; i * i <= n; ++i) {
        ll div1 = i;
        ll div2 = n / i;

        sum = (sum + div1 * (div2 - div1 + 1) % MOD) % MOD;

        if (div1 != div2) {
            ll low = n / (div1 + 1);
            ll high = n / div1;

            ll contrib = ((high * (high + 1) / 2) % MOD - (low * (low + 1) / 2) % MOD + MOD) % MOD;
            sum = (sum + i * contrib) % MOD;
        }
    }
    return sum;
}

int main() {
    ll n;
    cin >> n;
    cout << sumOfDivisors(n) << endl;
    return 0;
}