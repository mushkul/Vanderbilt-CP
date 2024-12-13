#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));
    dp[0][0] = 1;

    for (int col = 0; col < m; ++col) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[col][mask] == 0) continue;
            for (int newMask = 0; newMask < (1 << n); ++newMask) {
                bool valid = true;
                for (int row = 0; row < n; ++row) {
                    bool taken1 = (mask & (1 << row)) > 0;
                    bool taken2 = (newMask & (1 << row)) > 0;
                    if (taken1 && taken2) valid = false;
                }
                if (!valid) continue;
                    
                int lastRow = (newMask | mask);
                if ((lastRow ^ ((1 << n) - 1)) == 0) {
                    dp[col + 1][newMask] = (dp[col + 1][newMask] + dp[col][mask]) % MOD;
                }
            }
        }
    }

    cout << dp[m][0] << endl;
    return 0;
}