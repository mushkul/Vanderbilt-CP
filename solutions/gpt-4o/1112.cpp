#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int ALPHABET_SIZE = 26;

vector<int> computeKMPTable(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    for (int i = 1, len = 0; i < m;) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

int main() {
    int n;
    cin >> n;
    string pattern;
    cin >> pattern;
    int m = pattern.size();

    vector<int> lps = computeKMPTable(pattern);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            for (char c = 'A'; c <= 'Z'; ++c) {
                int k = j;
                while (k > 0 && pattern[k] != c) {
                    k = lps[k - 1];
                }
                if (k < m && pattern[k] == c) {
                    k++;
                }
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % MOD;
            }
        }
    }

    int result = 0;
    for (int j = 0; j <= m; ++j) {
        if (j == m) {
            result = (result + dp[n][j]) % MOD;
        }
    }

    cout << result << endl;
    return 0;
}