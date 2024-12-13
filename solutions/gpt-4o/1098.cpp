#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int nim_sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nim_sum ^= (x % 4);
        }
        if (nim_sum)
            cout << "first\n";
        else
            cout << "second\n";
    }
    return 0;
}