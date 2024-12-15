#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    for(long long k=1; k<=n; ++k) {
        long long total_positions = (k * k) * (k * k - 1) / 2;
        long long attack_positions = 4 * (k - 1) * (k - 2);
        cout << total_positions - attack_positions << endl;
    }
    return 0;
}