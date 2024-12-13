#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= x; ++j) {
            if (dp[i][j] == 0) continue;
            int maxSkill = t[i];
            for (int k = i; k < n; ++k) {
                maxSkill = max(maxSkill, t[k]);
                int penalty = maxSkill - t[i];
                if (j + penalty <= x) {
                    dp[k+1][j + penalty] = (dp[k+1][j + penalty] + dp[i][j]) % MOD;
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= x; ++i) {
        result = (result + dp[n][i]) % MOD;
    }

    cout << result << endl;
    return 0;
}