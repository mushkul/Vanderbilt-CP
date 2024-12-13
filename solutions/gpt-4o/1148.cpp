#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> forest(n, vector<char>(m));
    vector<vector<int>> horizontal(n, vector<int>(m));
    vector<vector<int>> vertical(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> forest[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = m - 1; j >= 0; --j) {
            if (forest[i][j] == '*') {
                horizontal[i][j] = 0;
            } else {
                horizontal[i][j] = 1 + (j < m - 1 ? horizontal[i][j + 1] : 0);
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = n - 1; i >= 0; --i) {
            if (forest[i][j] == '*') {
                vertical[i][j] = 0;
            } else {
                vertical[i][j] = 1 + (i < n - 1 ? vertical[i + 1][j] : 0);
            }
        }
    }

    for (int h = 0; h < n; ++h) {
        for (int w = 0; w < m; ++w) {
            int ways = 0;
            for (int i = 0; i + h < n; ++i) {
                for (int j = 0; j + w < m; ++j) {
                    if (vertical[i][j] > h && horizontal[i][j] > w) {
                        ++ways;
                    }
                }
            }
            cout << ways << (w == m - 1 ? '\n' : ' ');
        }
    }

    return 0;
}