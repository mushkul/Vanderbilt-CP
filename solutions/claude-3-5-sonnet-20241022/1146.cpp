#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    
    ll ans = 0;
    ll power = 1;
    ll groups = n;
    
    while (groups > 0) {
        ll complete = (groups - 1) / 2;
        ll remainder = groups % 2;
        
        ans += complete * power;
        if (remainder) {
            ans += (n % power) + 1;
        }
        
        groups /= 2;
        power *= 2;
    }
    
    cout << ans << endl;
    return 0;
}