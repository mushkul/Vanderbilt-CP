#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x = i;
        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            if (digit > 0) {
                dp[i] = std::min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    std::cout << dp[n] << std::endl;
    return 0;
}