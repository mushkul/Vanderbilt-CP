#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<ll> a;

bool check(ll x) {
    ll sum = 0;
    int groups = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] > x) return false;
        if(sum + a[i] > x) {
            sum = a[i];
            groups++;
        } else {
            sum += a[i];
        }
    }
    return groups <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    a.resize(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    
    ll l = 0, r = sum;
    ll ans = sum;
    while(l <= r) {
        ll mid = l + (r-l)/2;
        if(check(mid)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    cout << ans << "\n";
    return 0;
}