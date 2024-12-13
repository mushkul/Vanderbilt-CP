#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> h(n), s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    
    std::vector<int> dp(x + 1, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= h[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    
    std::cout << dp[x] << std::endl;
    
    return 0;
}