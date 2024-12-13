#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        x[i] = x[i - 1] ^ value;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << (x[b] ^ x[a - 1]) << endl;
    }

    return 0;
}