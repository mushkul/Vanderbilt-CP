#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp) {
        if (exp % 2) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll mod_inv(ll a, ll mod) {
    return mod_exp(a, mod - 2, mod);
}

ll comb(ll n, ll k, vector<ll>& fact, vector<ll>& inv_fact) {
    if (k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> traps(m);
    for (int i = 0; i < m; ++i) {
        cin >> traps[i].first >> traps[i].second;
    }

    traps.emplace_back(n, n);
    sort(traps.begin(), traps.end());

    vector<ll> fact(2 * n + 1), inv_fact(2 * n + 1);
    fact[0] = inv_fact[0] = 1;
    for (ll i = 1; i <= 2 * n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = mod_inv(fact[i], MOD);
    }

    int sz = traps.size();
    vector<ll> dp(sz);

    for (int i = 0; i < sz; ++i) {
        int y1 = traps[i].first, x1 = traps[i].second;
        dp[i] = comb(y1 + x1 - 2, y1 - 1, fact, inv_fact);

        for (int j = 0; j < i; ++j) {
            int y2 = traps[j].first, x2 = traps[j].second;
            if (x2 <= x1 && y2 <= y1) {
                dp[i] = (dp[i] - dp[j] * comb(y1 - y2 + x1 - x2, y1 - y2, fact, inv_fact) % MOD + MOD) % MOD;
            }
        }
    }

    cout << dp.back() << "\n";

    return 0;
}