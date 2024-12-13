#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p, xor_sum = 0;
        cin >> n;
        bool hasNonZero = false;
        for (int i = 1; i <= n; ++i) {
            cin >> p;
            if (i < n) xor_sum ^= p;
            if (p) hasNonZero = true;
        }
        if ((xor_sum == 0 && hasNonZero) || !hasNonZero) cout << "second\n";
        else cout << "first\n";
    }
    return 0;
}