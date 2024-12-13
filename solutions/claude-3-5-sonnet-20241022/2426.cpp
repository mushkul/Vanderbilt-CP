#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    
    vector<pair<ll,pair<ll,ll>>> diff(n);
    for(int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        diff[i] = {x-y, {x,y}};
    }
    
    sort(diff.rbegin(), diff.rend());
    
    ll ans = 0;
    for(int i = 0; i < a; i++) {
        ans += diff[i].second.first;
    }
    
    sort(diff.begin() + a, diff.end());
    for(int i = 0; i < b; i++) {
        ans += diff[i+a].second.second;
    }
    
    cout << ans << endl;
    return 0;
}