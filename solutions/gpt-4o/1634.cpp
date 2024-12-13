#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }
    
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dp(x + 1, INF);
    dp[0] = 0;
    
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INF) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    if (dp[x] == INF) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << dp[x] << std::endl;
    }
    
    return 0;
}