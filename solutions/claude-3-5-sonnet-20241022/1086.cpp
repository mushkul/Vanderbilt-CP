#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countDigits(ll num) {
    ll count[10] = {0};
    while (num > 0) {
        count[num % 10]++;
        num /= 10;
    }
    return *max_element(count, count + 10);
}

ll solve(ll n) {
    ll left = 1, right = 1e18;
    ll ans = 0;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (countDigits(mid) <= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    cout << solve(n) << '\n';
    
    return 0;
}