#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long binomialCoeff(int n, int k) {
    if (k > n) return 0;
    vector<long long> C(k + 1, 0);
    C[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--) {
            C[j] = (C[j] + C[j-1]) % MOD;
        }
    }
    return C[k];
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << binomialCoeff(n + m - 1, m) << endl;
    return 0;
}