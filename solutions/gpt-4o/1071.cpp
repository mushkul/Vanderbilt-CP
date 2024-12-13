#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long y, x;
        cin >> y >> x;
        long long max_n = max(y, x);
        long long max_n_square = max_n * max_n;
        long long number;
        if (max_n % 2 == 0) {
            if (x == max_n) {
                number = max_n_square - y + 1;
            } else {
                number = (max_n - 1) * (max_n - 1) + x;
            }
        } else {
            if (y == max_n) {
                number = max_n_square - x + 1;
            } else {
                number = (max_n - 1) * (max_n - 1) + y;
            }
        }
        cout << number << "\n";
    }
    return 0;
}