#include <iostream>
using namespace std;
typedef long long ll;

ll countBits(ll n) {
    ll total = 0;
    for (ll i = 1; i <= n; i++) {
        ll num = i;
        while (num) {
            total += num & 1;
            num >>= 1;
        }
    }
    return total;
}

int main() {
    ll n;
    cin >> n;
    cout << countBits(n) << endl;
    return 0;
}