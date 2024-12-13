#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<char>> grid(n, std::vector<char>(n));
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }
    
    if (grid[0][0] == '*') {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    dp[0][0] = 1;
    
    for (int i = 1; i < n; i++) {
        if (grid[i][0] == '.') {
            dp[i][0] = dp[i-1][0];
        }
    }
    
    for (int j = 1; j < n; j++) {
        if (grid[0][j] == '.') {
            dp[0][j] = dp[0][j-1];
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            }
        }
    }
    
    std::cout << dp[n-1][n-1] << std::endl;
    
    return 0;
}