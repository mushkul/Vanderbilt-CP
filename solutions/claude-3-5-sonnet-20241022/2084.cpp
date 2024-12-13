#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    
    vector<ll> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    vector<ll> f(n);
    for(int i = 0; i < n; i++) {
        cin >> f[i];
    }
    
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, LLONG_MAX));
    dp[0][0] = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            if(dp[i][j] == LLONG_MAX) continue;
            
            ll curr_skill = (j == 0 ? x : f[j-1]);
            
            if(i < n-1) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            }
            
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + s[i] * curr_skill);
        }
    }
    
    ll ans = LLONG_MAX;
    for(int j = 0; j <= n; j++) {
        ans = min(ans, dp[n][j]);
    }
    
    cout << ans << endl;
    
    return 0;
}