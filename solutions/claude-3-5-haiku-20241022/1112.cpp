#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX_N = 1005;
const int MAX_M = 105;
const int ALPHABET = 26;

int n, m;
string pattern;
long long dp[MAX_N][MAX_M][2];

int main() {
    cin >> n >> pattern;
    m = pattern.length();

    dp[0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[i][j][k] == 0) continue;

                for (char c = 'A'; c <= 'Z'; c++) {
                    int nj = j, nk = k;
                    while (nj > 0 && c != pattern[nj]) {
                        nj = lps[nj - 1];
                    }
                    if (c == pattern[nj]) {
                        nj++;
                    }
                    if (nj == m) {
                        nj = lps[nj - 1];
                        nk = 1;
                    }
                    dp[i + 1][nj][nk] = (dp[i + 1][nj][nk] + dp[i][j][k]) % MOD;
                }
            }
        }
    }

    long long result = 0;
    for (int j = 0; j < m; j++) {
        result = (result + dp[n][j][1]) % MOD;
    }

    cout << result << endl;
    return 0;
}