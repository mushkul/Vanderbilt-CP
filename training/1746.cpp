#include <bits/stdc++.h>

const int MOD = 1e9+7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(m + 1, 0));

    if (x[0] == 0) {
        for (int v = 1; v <= m; v++) {
            dp[0][v] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (x[i] == 0) {
            for (int v = 1; v <= m; v++) {
                dp[i][v] = ((dp[i-1][v] + (v > 1 ? dp[i-1][v-1] : 0)) % MOD + 
                            (v < m ? dp[i-1][v+1] : 0)) % MOD;
            }
        } else {
            int v = x[i];
            dp[i][v] = ((dp[i-1][v] + (v > 1 ? dp[i-1][v-1] : 0)) % MOD + 
                        (v < m ? dp[i-1][v+1] : 0)) % MOD;
        }
    }

    int result = 0;
    for (int v = 1; v <= m; v++) {
        result = (result + dp[n-1][v]) % MOD;
    }

    std::cout << result << "\n";
    return 0;
}