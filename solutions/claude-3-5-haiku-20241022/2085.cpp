#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> s(n), f(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> f[i];
    
    vector<ll> dp(n, LLONG_MAX);
    dp[n-1] = (ll)s[n-1] * x;
    
    for (int i = n-2; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            ll time = (ll)s[i] * x + dp[j];
            dp[i] = min(dp[i], time);
        }
        x = f[i];
    }
    
    ll result = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        result = min(result, dp[i]);
    }
    
    cout << result << endl;
    return 0;
}