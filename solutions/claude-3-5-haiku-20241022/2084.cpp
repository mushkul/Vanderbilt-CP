#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> s(n), f(n);
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    
    vector<ll> dp(n, LLONG_MAX);
    dp[0] = s[0] * x;
    
    for (int i = 1; i < n-1; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] != LLONG_MAX) {
                dp[i] = min(dp[i], dp[j] + s[i] * f[j]);
            }
        }
    }
    
    ll minTime = LLONG_MAX;
    for (int j = 0; j < n-1; j++) {
        if (dp[j] != LLONG_MAX) {
            minTime = min(minTime, dp[j] + s[n-1] * f[j]);
        }
    }
    
    cout << minTime << endl;
    
    return 0;
}