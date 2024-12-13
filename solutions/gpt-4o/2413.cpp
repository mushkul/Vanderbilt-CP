#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int t;
    std::cin >> t;
    std::vector<int> test_cases(t);
    for (int i = 0; i < t; ++i) {
        std::cin >> test_cases[i];
    }

    int max_n = *max_element(test_cases.begin(), test_cases.end());
    std::vector<long long> dp_straight(max_n + 1), dp_diagonal(max_n + 1);

    dp_straight[1] = 1;
    dp_diagonal[1] = 1;

    for (int i = 2; i <= max_n; ++i) {
        dp_straight[i] = (2 * dp_straight[i - 1] + dp_diagonal[i - 1]) % MOD;
        dp_diagonal[i] = (4 * dp_diagonal[i - 1] + dp_straight[i - 1]) % MOD;
    }

    for (int i = 0; i < t; ++i) {
        int n = test_cases[i];
        long long result = (dp_straight[n] + dp_diagonal[n]) % MOD;
        std::cout << result << "\n";
    }

    return 0;
}