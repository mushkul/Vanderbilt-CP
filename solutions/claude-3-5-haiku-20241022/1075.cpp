#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
    const int MOD = 1e9 + 7;
    
    for (int j = 1; j <= n; j++) {
        dp[1][j] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (abs(j - k) != 1) {
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                }
            }
        }
    }
    
    long long result = 0;
    for (int j = 1; j <= n; j++) {
        result = (result + dp[n][j]) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}