#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

long long modInverse(long long a, long long m) {
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    if (x1 < 0) x1 += m0;
    return x1;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> factors(n);
    for (int i = 0; i < n; ++i) {
        cin >> factors[i].first >> factors[i].second;
    }
    
    long long numDivisors = 1, sumDivisors = 1, prodDivisors = 1;

    for (int i = 0; i < n; ++i) {
        int p = factors[i].first;
        int a = factors[i].second;

        numDivisors = numDivisors * (a + 1) % MOD;
        
        long long term = 1, pTerm = 1;
        for (int j = 0; j <= a; ++j) {
            sumDivisors = sumDivisors * (pTerm) % MOD;
            pTerm = pTerm * p % MOD;
        }
        sumDivisors = sumDivisors * modInverse(p - 1, MOD) % MOD;
        sumDivisors = sumDivisors * (p - 1 + MOD) % MOD;
        
        long long exp = a * (a + 1LL) / 2 % (MOD - 1);
        exp = exp * (numDivisors / (a + 1) % (MOD - 1)) % (MOD - 1);
        
        pTerm = 1;
        for (long long j = 0; j < exp; ++j) {
            pTerm = pTerm * p % MOD;
        }
        prodDivisors = prodDivisors * pTerm % MOD;
    }
    
    cout << numDivisors << " " << sumDivisors << " " << prodDivisors << endl;
    return 0;
}