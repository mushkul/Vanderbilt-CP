#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    
    if (n % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    n /= 2; // we need to find C(n) = C(2n, n) / (n + 1) where C(n, k) is binomial coefficient
    
    long long catalan[n + 1];
    catalan[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        catalan[i] = catalan[i - 1] * (4 * i - 2) % MOD * (MOD + 1) / i % MOD;
    }
    
    cout << catalan[n] << endl;
    
    return 0;
}