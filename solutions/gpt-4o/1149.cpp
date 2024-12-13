#include <iostream>
#include <vector>
#include <string>
#define MOD 1000000007

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> last(26, -1);
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Empty string case

    for (int i = 1; i <= n; ++i) {
        dp[i] = (dp[i - 1] * 2) % MOD;
        if (last[s[i-1] - 'a'] != -1) {
            dp[i] = (dp[i] - dp[last[s[i-1] - 'a']] + MOD) % MOD;
        }
        last[s[i-1] - 'a'] = i - 1;
    }

    cout << (dp[n] - 1 + MOD) % MOD << endl;
    return 0;
}