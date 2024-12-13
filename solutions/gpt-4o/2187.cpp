#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    string prefix;
    cin >> n >> prefix;

    int k = prefix.length();
    int open = 0, close = 0;
    for (char c : prefix) {
        if (c == '(') open++;
        else close++;
        if (close > open) {
            cout << 0 << endl;
            return 0;
        }
    }

    int remaining_open = n / 2 - open;
    int remaining_close = n / 2 - close;
    if (remaining_open < 0 || remaining_close < 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<int>> dp(remaining_open + 1, vector<int>(remaining_close + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i <= remaining_open; ++i) {
        for (int j = 0; j <= remaining_close; ++j) {
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j > 0 && j > i) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }

    cout << dp[remaining_open][remaining_close] << endl;
    return 0;
}