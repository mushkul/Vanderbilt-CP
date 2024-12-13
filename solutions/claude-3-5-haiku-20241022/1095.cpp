#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;

long long power(long long a, long long b) {
    long long result = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n--) {
        long long a, b;
        cin >> a >> b;
        cout << power(a, b) << "\n";
    }

    return 0;
}