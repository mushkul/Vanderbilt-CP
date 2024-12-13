#include <bits/stdc++.h>
using namespace std;

const int N = 50;
int n, a[N], b[N], grid[N][N], chosen[N][N];
int row_sum[N], col_sum[N];

int solve() {
    for (int mask = 0; mask < (1 << (n * n)); ++mask) {
        fill(row_sum, row_sum + n, 0);
        fill(col_sum, col_sum + n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                chosen[i][j] = (mask & (1 << (i * n + j))) ? 1 : 0;
                if (chosen[i][j]) {
                    row_sum[i]++;
                    col_sum[j]++;
                }
            }
        }
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (row_sum[i] != a[i] || col_sum[i] != b[i]) {
                valid = false;
                break;
            }
        }
        if (valid) {
            int total = 0;
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (chosen[i][j])
                        total += grid[i][j];
            return total;
        }
    }
    return -1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];

    int result = solve();
    if (result == -1) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << (chosen[i][j] ? 'X' : '.');
            }
            cout << endl;
        }
    }
    return 0;
}