#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> heaps(n);
        int nim_sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> heaps[i];
            nim_sum ^= heaps[i] % 4;
        }

        cout << (nim_sum ? "first" : "second") << "\n";
    }

    return 0;
}