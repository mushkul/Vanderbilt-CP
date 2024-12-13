#include <iostream>
#include <vector>

const int MOD = 1000000007;

long long binomial_coefficient(int n, int k, std::vector<long long>& fact, std::vector<long long>& inv_fact) {
    if (k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

long long power_mod(long long base, long long exp, int mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<long long> fact(n + m + 1), inv_fact(n + m + 1);
    fact[0] = 1;
    for (int i = 1; i <= n + m; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv_fact[n + m] = power_mod(fact[n + m], MOD - 2, MOD);
    for (int i = n + m - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    long long result = binomial_coefficient(n + m - 1, m, fact, inv_fact);
    std::cout << result << '\n';
    return 0;
}