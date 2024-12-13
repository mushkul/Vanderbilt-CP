#include <iostream>
#include <cmath>

const int MOD = 1000000007;
const int PHI_MOD = MOD - 1;

long long mod_exp(long long base, long long exp, long long mod) {
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

long long mod_exp_exp(long long b, long long c) {
    return mod_exp(b % PHI_MOD, c, PHI_MOD);
}

int main() {
    int n;
    std::cin >> n;
    
    while (n--) {
        long long a, b, c;
        std::cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) {
            std::cout << 1 << std::endl;
            continue;
        }

        long long exp = mod_exp_exp(b, c);
        std::cout << mod_exp(a, exp, MOD) << std::endl;
    }

    return 0;
}