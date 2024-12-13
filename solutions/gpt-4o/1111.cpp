#include <iostream>
#include <string>
#include <vector>

std::string longestPalindrome(const std::string &s) {
    int n = s.size();
    if (n == 0) return "";
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    int maxLength = 1;
    int start = 0;

    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                maxLength = len;
            }
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << longestPalindrome(s) << std::endl;
    return 0;
}