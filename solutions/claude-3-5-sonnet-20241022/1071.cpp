#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--) {
        ll y, x;
        cin >> y >> x;
        
        ll ans;
        if(y > x) {
            if(y % 2 == 0) {
                ans = y * y - x + 1;
            } else {
                ans = (y-1) * (y-1) + x;
            }
        } else {
            if(x % 2 == 1) {
                ans = x * x - y + 1;
            } else {
                ans = (x-1) * (x-1) + y;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}