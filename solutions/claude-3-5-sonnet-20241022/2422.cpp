#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    ll target = (n * n + 1) / 2;
    ll l = 1, r = n * n;
    
    while (l < r) {
        ll mid = l + (r - l) / 2;
        ll cnt = 0;
        
        for (ll i = 1; i <= n; i++) {
            cnt += min(n, mid / i);
        }
        
        if (cnt < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    
    cout << l << "\n";
    
    return 0;
}