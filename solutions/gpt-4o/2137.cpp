#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j) {
            grid[i][j] = line[j] - '0';
        }
    }

    long long beautiful_subgrids = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int common_black_columns = 0;
            for (int k = 0; k < n; ++k) {
                if (grid[i][k] && grid[j][k]) {
                    ++common_black_columns;
                }
            }
            if (common_black_columns >= 2) {
                beautiful_subgrids += common_black_columns * (common_black_columns - 1) / 2;
            }
        }
    }

    cout << beautiful_subgrids << endl;
    return 0;
}