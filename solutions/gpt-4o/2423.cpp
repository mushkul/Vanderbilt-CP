#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fillTrominos(int n, int m) {
    vector<string> grid(n, string(m, 'A'));
    char letter = 'A';

    for (int i = 0; i + 2 < n; i += 3) {
        for (int j = 0; j + 2 < m; j += 3) {
            grid[i][j] = letter;
            grid[i][j + 1] = letter;
            grid[i + 1][j] = letter;
            letter = (letter - 'A' + 1) % 26 + 'A';

            grid[i + 1][j + 1] = letter;
            grid[i + 2][j + 1] = letter;
            grid[i + 2][j] = letter;
            letter = (letter - 'A' + 1) % 26 + 'A';

            grid[i + 1][j + 2] = letter;
            grid[i][j + 2] = letter;
            grid[i + 2][j + 2] = letter;
            letter = (letter - 'A' + 1) % 26 + 'A';
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << grid[i] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if ((n * m) % 3 != 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            fillTrominos(n, m);
        }
    }
    return 0;
}