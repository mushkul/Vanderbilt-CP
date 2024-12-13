#include <iostream>
#include <vector>
#include <numeric>
#define MOD 1000000007

using namespace std;

long long binpow(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b /= 2;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> phi(n);
    iota(phi.begin(), phi.end(), 0);
    for (int i = 2; i < n; ++i) {
        if (phi[i] == i) {
            for (int j = i; j < n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }

    long long result = 0;
    for (int d = 1; d <= n; ++d) {
        if (n % d == 0) {
            result = (result + phi[d] * binpow(m, n / d, MOD)) % MOD;
        }
    }

    result = result * binpow(n, MOD - 2, MOD) % MOD;
    cout << result << endl;

    return 0;
}