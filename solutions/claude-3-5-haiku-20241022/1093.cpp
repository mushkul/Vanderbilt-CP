#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    int n;
    cin >> n;
 
    int total_sum = n * (n + 1) / 2;
    if (total_sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
 
    int target_sum = total_sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target_sum + 1, 0));
    dp[0][0] = 1;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target_sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= i) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-i]) % MOD;
            }
        }
    }
 
    cout << (dp[n][target_sum] / 2) % MOD << endl;
 
    return 0;
}