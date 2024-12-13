#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        for(int sum = 1; sum <= x; sum++) {
            if(sum >= coins[i]) {
                dp[sum] = (dp[sum] + dp[sum - coins[i]]) % MOD;
            }
        }
    }
    
    cout << dp[x] << '\n';
    
    return 0;
}