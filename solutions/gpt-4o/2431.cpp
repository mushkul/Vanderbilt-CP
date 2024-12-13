#include <iostream>
#include <vector>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        long long length = 0, digits = 1, count = 9;
        while (k > length + digits * count) {
            length += digits * count;
            digits++;
            count *= 10;
        }
        long long num = (k - length - 1) / digits + 1;
        long long index = (k - length - 1) % digits;
        long long start = 1;
        for (int i = 1; i < digits; ++i) start *= 10;
        start += num - 1;
        cout << to_string(start)[index] << endl;
    }
    return 0;
}