#include <iostream>
#include <vector>

const int MOD = 1000000007;

// Fast power function
long long mod_exp(long long x, long long y, long long mod) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return result;
}

// Modular inverse using Fermat's little theorem
long long mod_inv(long long x, long long mod) {
    return mod_exp(x, mod - 2, mod);
}

// Binomial coefficient with modulus
long long binomial_coeff(int n, int k, const std::vector<long long>& fact, const std::vector<long long>& ifact) {
    if (k > n || k < 0) return 0;
    return fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    // Prepare factorials and inverse factorials for binomial coefficients
    std::vector<long long> fact(2 * n + 1, 1), ifact(2 * n + 1, 1);
    for (int i = 2; i <= 2 * n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    ifact[2 * n] = mod_inv(fact[2 * n], MOD);
    for (int i = 2 * n - 1; i > 0; --i) {
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    }

    // Count valid placements of k bishops
    long long result = 0;
    for (int d1 = 0; d1 <= 2 * n - 2; ++d1) {
        for (int d2 = 0; d2 <= 2 * n - 2; ++d2) {
            int b1 = std::min(d1 + 1, 2 * n - 1 - d1);
            int b2 = std::min(d2 + 1, 2 * n - 1 - d2);
            long long ways1 = binomial_coeff(b1, k, fact, ifact);
            long long ways2 = binomial_coeff(b2, k, fact, ifact);
            int overlap = std::abs(d1 - d2);
            int overlap_b = std::min(n, n - overlap);
            long long ways_overlap = binomial_coeff(overlap_b, k, fact, ifact);
            result = (result + MOD + (ways1 * ways2 % MOD) - ways_overlap) % MOD;
        }
    }

    // Scale result to count unique pairs (d1, d2)
    result = result * mod_inv(2, MOD) % MOD * mod_inv(2, MOD) % MOD;
    std::cout << result << "\n";

    return 0;
}