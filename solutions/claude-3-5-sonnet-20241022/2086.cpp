#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<ll> pref(n+1);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + a[i];
    }
    
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 1e18));
    dp[0][0] = 0;
    
    for(int j = 1; j <= k; j++) {
        for(int i = j; i <= n; i++) {
            for(int prev = j-1; prev < i; prev++) {
                ll sum = pref[i] - pref[prev];
                dp[i][j] = min(dp[i][j], dp[prev][j-1] + sum*sum);
            }
        }
    }
    
    cout << dp[n][k] << endl;
    return 0;
}