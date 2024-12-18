#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long mod_exp(long long base, long long exp, int mod) {
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

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long a, b;
        cin >> a >> b;
        cout << mod_exp(a, b, MOD) << '\n';
    }
    return 0;
}