#include <iostream>
using namespace std;

long long trailingZeros(int n) {
    long long zeros = 0;
    for (int i = 5; i <= n; i *= 5) {
        zeros += n / i;
    }
    return zeros;
}

int main() {
    int n;
    cin >> n;
    cout << trailingZeros(n) << endl;
    return 0;
}