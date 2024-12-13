#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        vector<ll> subset(coins.begin() + a - 1, coins.begin() + b);
        sort(subset.begin(), subset.end());
        
        ll smallest_missing_sum = 1;
        for (ll coin : subset) {
            if (coin > smallest_missing_sum) break;
            smallest_missing_sum += coin;
        }
        
        cout << smallest_missing_sum << "\n";
    }

    return 0;
}