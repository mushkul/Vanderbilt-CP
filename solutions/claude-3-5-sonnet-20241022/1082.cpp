#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll MOD = 1e9+7;
 
ll sum(ll n) {
    n %= MOD;
    return n * (n + 1) % MOD * ((MOD + 1) / 2) % MOD;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    ll result = 0;
    ll i = 1;
    
    while(i <= n) {
        ll q = n / i;
        ll j = n / q;
        
        ll contribution = (sum(j) - sum(i-1) + MOD) % MOD;
        result = (result + q * contribution % MOD) % MOD;
        
        i = j + 1;
    }
    
    cout << result << "\n";
    
    return 0;
}