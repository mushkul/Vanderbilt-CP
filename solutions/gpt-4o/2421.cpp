#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1e9+7;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j] == 0) continue;
            for (int k = 0; k < 26; ++k) {
                if (freq[k] > j + 1) continue;
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j] * (freq[k] - j)) % MOD;
            }
        }
    }
    
    cout << dp[n][0] << endl;
    return 0;
}