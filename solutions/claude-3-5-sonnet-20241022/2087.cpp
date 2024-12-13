#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
vector<ll> c;
vector<vector<ll>> dp;
vector<vector<ll>> cost;

ll calc_cost(int l, int r) {
    ll ans = 0;
    int med = (l + r) / 2;
    for(int i = l; i <= r; i++) {
        ans += c[i] * abs(i - med);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    c.resize(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    
    cost.assign(n, vector<ll>(n));
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cost[i][j] = calc_cost(i, j);
        }
    }
    
    dp.assign(k+1, vector<ll>(n, 1e18));
    
    for(int i = 0; i < n; i++) {
        dp[1][i] = cost[0][i];
    }
    
    for(int i = 2; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            for(int prev = 0; prev < j; prev++) {
                dp[i][j] = min(dp[i][j], dp[i-1][prev] + cost[prev+1][j]);
            }
        }
    }
    
    cout << dp[k][n-1] << "\n";
    
    return 0;
}