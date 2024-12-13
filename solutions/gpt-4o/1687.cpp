#include <iostream>
#include <vector>
using namespace std;

const int LOG = 18;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> boss(n + 1);
    vector<vector<int>> up(n + 1, vector<int>(LOG));

    // Read the direct bosses
    boss[1] = 0; // General director, No boss
    for (int i = 2; i <= n; ++i) {
        cin >> boss[i];
    }

    // Preprocessing: Binary lifting
    for (int i = 1; i <= n; ++i) {
        up[i][0] = boss[i]; // 2^0th boss
    }
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (up[i][j - 1] != 0) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            } else {
                up[i][j] = 0;
            }
        }
    }

    // Processing queries
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int j = 0; j < LOG && x > 0; ++j) {
            if (k & (1 << j)) {
                x = up[x][j];
            }
        }
        cout << (x > 0 ? x : -1) << "\n";
    }

    return 0;
}