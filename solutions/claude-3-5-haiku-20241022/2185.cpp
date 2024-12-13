#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, vector<ll>& primes) {
    ll result = 0;
    ll k = primes.size();
    
    for (ll mask = 1; mask < (1 << k); ++mask) {
        ll divisor = 1;
        ll bits = 0;
        
        for (ll i = 0; i < k; ++i) {
            if (mask & (1 << i)) {
                divisor *= primes[i];
                bits++;
            }
        }
        
        if (bits % 2 == 1)
            result += n / divisor;
        else
            result -= n / divisor;
    }
    
    return result;
}

int main() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> primes(k);
    for (ll i = 0; i < k; ++i)
        cin >> primes[i];
    
    cout << solve(n, primes) << endl;
    
    return 0;
}