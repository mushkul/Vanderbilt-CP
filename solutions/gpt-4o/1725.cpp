#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(6 * n + 1, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= 6 * i; ++j) {
            for (int k = 1; k <= 6; ++k) {
                if (j - k >= 0) {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
    }
    
    long long favorable = 0;
    for (int sum = a; sum <= b; ++sum) {
        favorable += dp[n][sum];
    }
    
    long long total_ways = 1;
    for (int i = 0; i < n; ++i) {
        total_ways *= 6;
    }
    
    double probability = static_cast<double>(favorable) / total_ways;
    std::cout << std::fixed << std::setprecision(6) << probability << std::endl;
    
    return 0;
}