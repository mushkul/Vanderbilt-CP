#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> machines(n);
    for(int i = 0; i < n; i++) cin >> machines[i];
    ll left = 1, right = 1e18;
    while(left < right) {
        ll mid = left + (right - left) / 2;
        ll sum = 0;
        for(int i = 0; i < n && sum <= t; i++) sum += mid / machines[i];
        if(sum >= t) right = mid;
        else left = mid + 1;
    }
    cout << left;
    return 0;
}