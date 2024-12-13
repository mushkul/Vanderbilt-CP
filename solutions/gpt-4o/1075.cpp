#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    if (n == 2) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::vector<long long> dp(n + 1);
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 2;

    for (int i = 4; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2] * (i - 1)) % MOD;
    }

    std::cout << dp[n] << std::endl;
    return 0;
}