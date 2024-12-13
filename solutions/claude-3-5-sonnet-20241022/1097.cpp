#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<vector<ll>> dp(n, vector<ll>(n));
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                dp[i][j] = a[i];
            }
            else {
                dp[i][j] = max(a[i] - dp[i+1][j], a[j] - dp[i][j-1]);
            }
        }
    }
    
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    
    cout << (sum + dp[0][n-1])/2 << endl;
    
    return 0;
}