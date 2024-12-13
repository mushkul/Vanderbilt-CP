#include <iostream>
#include <vector>

const int MOD = 1000000007;
const int MAX = 1000000;

std::vector<long long> fact(MAX + 1), invFact(MAX + 1);

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void precomputeFactorials() {
    fact[0] = 1;
    for (int i = 1; i <= MAX; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invFact[MAX] = modExp(fact[MAX], MOD - 2, MOD);
    for (int i = MAX - 1; i >= 0; --i) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long binomialCoefficient(int a, int b) {
    if (b > a) return 0;
    return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
}

int main() {
    precomputeFactorials();
    int n;
    std::cin >> n;
    while (n--) {
        int a, b;
        std::cin >> a >> b;
        std::cout << binomialCoefficient(a, b) << "\n";
    }
    return 0;
}