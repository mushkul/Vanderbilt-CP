#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    for (int query = 0; query < q; query++) {
        int a, b;
        cin >> a >> b;
        
        vector<ll> subset_coins(coins.begin() + a - 1, coins.begin() + b);
        sort(subset_coins.begin(), subset_coins.end());

        ll missing = 1;
        for (ll coin : subset_coins) {
            if (coin > missing) break;
            missing += coin;
        }

        cout << missing << '\n';
    }

    return 0;
}