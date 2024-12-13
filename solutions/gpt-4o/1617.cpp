#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    const int MOD = 1e9 + 7;
    long long result = 1;
    for (int i = 0; i < n; ++i) {
        result = (result * 2) % MOD;
    }
    cout << result << endl;
    return 0;
}