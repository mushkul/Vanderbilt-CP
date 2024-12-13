#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll n, ll k) {
    if (n == 1) return 1;
    if (k <= (n + 1) / 2) {
        if (k % 2 == 0) return 2 * k;
        else return 2 * k - 1;
    }
    ll m = n / 2;
    ll pos = k - (n + 1) / 2;
    ll rec = solve(m, pos);
    return 2 * rec - 1 + (rec > pos);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << solve(n, k) << '\n';
    }
    
    return 0;
}