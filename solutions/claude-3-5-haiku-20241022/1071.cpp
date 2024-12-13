#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll solve(ll y, ll x) {
    ll maxLayer = max(y, x);
    ll base;
    
    if (maxLayer % 2 == 1) {
        if (y >= x) {
            base = (maxLayer * maxLayer) - (maxLayer - 1);
            return base + (x - 1);
        } else {
            base = (maxLayer * maxLayer);
            return base - (y - 1);
        }
    } else {
        if (x >= y) {
            base = ((maxLayer - 1) * (maxLayer - 1)) + 1;
            return base + (y - 1);
        } else {
            base = ((maxLayer - 1) * (maxLayer - 1)) + 1;
            return base - (x - 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        ll y, x;
        cin >> y >> x;
        cout << solve(y, x) << "\n";
    }
    
    return 0;
}