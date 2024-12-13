#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = result * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

long long modInverse(long long n, long long mod) {
    return modExp(n, mod - 2, mod);
}

long long countSequences(int n, int k) {
    if (k > n) return 0;
    vector<long long> factorial(n + 1, 1);
    for (int i = 2; i <= n; ++i)
        factorial[i] = factorial[i - 1] * i % MOD;

    long long total_sequences = modExp(k, n, MOD);
    long long invalid_sequences = 0;
    for (int i = 0; i < k; ++i) {
        long long term = modExp(k - i, n, MOD) * factorial[k] % MOD;
        term = term * modInverse(factorial[i], MOD) % MOD;
        term = term * modInverse(factorial[k - i], MOD) % MOD;
        if (i % 2 == 0)
            invalid_sequences = (invalid_sequences + term) % MOD;
        else
            invalid_sequences = (invalid_sequences - term + MOD) % MOD;
    }

    return ((total_sequences - invalid_sequences + MOD) % MOD);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << countSequences(n, k) << endl;
    return 0;
}