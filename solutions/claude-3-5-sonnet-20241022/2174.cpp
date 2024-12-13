#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll n) {
    if (n == 0) return 0;
    ll temp = n;
    vector<int> digits;
    while (temp > 0) {
        int digit = temp % 10;
        if (digit > 0) digits.push_back(digit);
        temp /= 10;
    }
    ll best = LLONG_MAX;
    for (int digit : digits) {
        if (n >= digit) {
            ll steps = 1 + solve(n - digit);
            best = min(best, steps);
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}