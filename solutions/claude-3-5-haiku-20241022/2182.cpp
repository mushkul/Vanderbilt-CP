#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

long long mod_inv(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}

int main() {
    int n;
    cin >> n;

    long long divisor_count = 1, divisor_sum = 1, divisor_product = 1;

    for (int i = 0; i < n; ++i) {
        long long x, k;
        cin >> x >> k;

        // Divisor count
        divisor_count = (divisor_count * (k + 1)) % MOD;

        // Divisor sum
        if (k == 1) divisor_sum = (divisor_sum * (x + 1)) % MOD;
        else {
            long long power_sum = (mod_pow(x, k + 1, MOD) - x) % MOD * mod_inv(x - 1, MOD) % MOD;
            divisor_sum = (divisor_sum * power_sum) % MOD;
        }

        // Divisor product
        long long product_exp = (divisor_count * (k * (k + 1) / 2)) % (MOD - 1);
        divisor_product = mod_pow(divisor_product * mod_pow(x, product_exp, MOD), 1, MOD);
    }

    cout << divisor_count << " " << divisor_sum << " " << divisor_product << endl;
    return 0;
}