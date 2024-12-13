#include <bits/stdc++.h>
using namespace std;

string get_longest_palindrome(string s) {
    if (s.empty()) return s;
    int n = s.size(), len = 1, start = 0;
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; i++) dp[i][i] = true;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            len = 2;
        }
    }
    for (int j = 3; j <= n; j++) {
        for (int i = 0; i < n - j + 1; i++) {
            int en = i + j - 1;
            if (s[i] == s[en] && dp[i + 1][en - 1]) {
                dp[i][en] = true;
                if (j > len) {
                    start = i;
                    len = j;
                }
            }
        }
    }
    return s.substr(start, len);
}

int main() {
    string s;
    cin >> s;
    cout << get_longest_palindrome(s);
    return 0;
}