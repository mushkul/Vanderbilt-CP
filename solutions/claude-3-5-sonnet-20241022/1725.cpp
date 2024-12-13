#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<ld> dp(6*n + 1);
    dp[0] = 1;
    
    for(int i = 0; i < n; i++) {
        vector<ld> new_dp(6*n + 1);
        for(int j = 0; j <= 6*i; j++) {
            for(int k = 1; k <= 6; k++) {
                new_dp[j+k] += dp[j] / 6;
            }
        }
        dp = new_dp;
    }
    
    ld sum = 0;
    for(int i = a; i <= b; i++) {
        sum += dp[i];
    }
    
    cout << fixed << setprecision(6) << sum << "\n";
    
    return 0;
}