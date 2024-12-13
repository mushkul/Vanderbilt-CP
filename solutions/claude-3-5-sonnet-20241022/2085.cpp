#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,x;
    cin >> n >> x;
    vector<ll> s(n), f(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> f[i];
    
    vector<vector<ll>> dp(n, vector<ll>(n+1, 1e18));
    dp[0][0] = s[0]*x;
    dp[0][1] = s[0]*x;
    
    for(int i = 1; i < n; i++) {
        for(int kills = 0; kills <= i+1; kills++) {
            if(kills == 0) continue;
            
            for(int prev = 0; prev <= kills; prev++) {
                if(dp[i-1][prev] == 1e18) continue;
                
                ll curr = dp[i-1][prev];
                ll factor = x;
                if(prev > 0) {
                    factor = f[i-1];
                    for(int j = i-2; j >= 0 && prev > 1; j--) {
                        if(prev - (i-j) > 0) {
                            factor = f[j];
                            break;
                        }
                    }
                }
                dp[i][kills] = min(dp[i][kills], curr + s[i]*factor);
            }
        }
    }
    
    ll ans = 1e18;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, dp[n-1][i]);
    }
    cout << ans << endl;
    return 0;
}