#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long count = 0;
    for (long long bit = 0; (1LL << bit) <= n; ++bit) {
        long long fullCycles = n / (1LL << (bit + 1));
        long long remainder = n % (1LL << (bit + 1));
        count += fullCycles * (1LL << bit) + max(0LL, remainder - (1LL << bit) + 1);
    }
    cout << count << endl;
    return 0;
}