#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0; // No cuts needed for a square
            } else {
                // Horizontal cuts
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
                }
                // Vertical cuts
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
                }
            }
        }
    }

    cout << dp[a][b] << endl;
    return 0;
}