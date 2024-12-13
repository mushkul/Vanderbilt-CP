#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = (long long)dp[i - 1][j - 1] + (long long)j * dp[i - 1][j] % MOD;
            dp[i][j] %= MOD;
        }
    }
    
    for (int k = 1; k <= n; ++k) {
        cout << dp[n][k] << endl;
    }
    
    return 0;
}