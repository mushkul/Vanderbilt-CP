#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

ll catalan(int n) {
    vector<ll> C(n + 1, 0);
    C[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            C[i] = (C[i] + C[j] * C[i - j - 1]) % MOD;
        }
    }
    
    return C[n];
}

int main() {
    int n;
    cin >> n;
    
    if (n % 2 == 1) {
        cout << 0 << endl;
    } else {
        cout << catalan(n/2) << endl;
    }
    
    return 0;
}