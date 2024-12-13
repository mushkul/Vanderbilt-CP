#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(k);
    for(ll i = 0; i < k; i++) {
        cin >> a[i];
    }
    
    ll ans = 0;
    for(ll mask = 1; mask < (1ll<<k); mask++) {
        ll product = 1;
        ll bits = 0;
        bool overflow = false;
        
        for(ll i = 0; i < k; i++) {
            if(mask & (1ll<<i)) {
                bits++;
                if(product > n/a[i]) {
                    overflow = true;
                    break;
                }
                product *= a[i];
            }
        }
        
        if(!overflow) {
            if(bits % 2 == 1) ans += n/product;
            else ans -= n/product;
        }
    }
    
    cout << ans;
    return 0;
}