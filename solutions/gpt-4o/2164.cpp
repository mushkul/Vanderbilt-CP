#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long n, k;
        cin >> n >> k;
        
        long long result = 0;
        for (long long i = 1; i <= n; ++i) {
            result = (result + 2) % i;
        }
        
        long long answer = (result + k - 1) % n + 1;
        cout << answer << '\n';
    }
    return 0;
}