#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int log = log2(n) + 1;
    vector<vector<int>> sparse(n, vector<int>(log));

    for (int i = 0; i < n; ++i) {
        sparse[i][0] = arr[i];
    }

    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        int l = b - a + 1;
        int j = log2(l);
        cout << min(sparse[a][j], sparse[b - (1 << j) + 1][j]) << "\n";
    }

    return 0;
}