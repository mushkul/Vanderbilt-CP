#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    long long num_ways = mod_pow(2, (long long)n * n, MOD);
    long long result = num_ways;
    result = (result + num_ways * mod_pow(mod_pow(2, n, MOD), MOD - 2, MOD) % MOD) % MOD;
    result = (result + num_ways * mod_pow(mod_pow(2, n, MOD), MOD - 2, MOD) % MOD) % MOD;
    result = (result + num_ways * mod_pow(mod_pow(2, n, MOD), MOD - 2, MOD) % MOD) % MOD;
    result = result * mod_pow(4, MOD - 2, MOD) % MOD;

    cout << result << endl;

    return 0;
}