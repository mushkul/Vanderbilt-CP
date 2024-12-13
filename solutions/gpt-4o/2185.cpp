#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll count_multiples(const vector<int>& primes, ll n) {
    int k = primes.size();
    ll total = 0;
    for (int mask = 1; mask < (1 << k); ++mask) {
        ll lcm = 1;
        int bits = __builtin_popcount(mask);
        for (int i = 0; i < k; ++i) {
            if ((mask >> i) & 1) {
                ll gcd = __gcd(lcm, (ll)primes[i]);
                lcm = (lcm / gcd) * primes[i];
                if (lcm > n) break;
            }
        }
        if (lcm <= n) {
            if (bits % 2) {
                total += n / lcm;
            } else {
                total -= n / lcm;
            }
        }
    }
    return total;
}

int main() {
    ll n;
    int k;
    cin >> n >> k;
    vector<int> primes(k);
    for (int i = 0; i < k; ++i) {
        cin >> primes[i];
    }
    cout << count_multiples(primes, n) << endl;
    return 0;
}