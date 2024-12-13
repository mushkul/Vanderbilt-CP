#include <iostream>
#include <vector>
using namespace std;

class BIT2D {
    vector<vector<int>> bit;
    int n;

public:
    BIT2D(int n) : n(n) {
        bit.assign(n + 1, vector<int>(n + 1, 0));
    }

    void update(int y, int x, int delta) {
        for (int i = y; i <= n; i += i & -i) {
            for (int j = x; j <= n; j += j & -j) {
                bit[i][j] += delta;
            }
        }
    }

    int sum(int y, int x) {
        int s = 0;
        for (int i = y; i > 0; i -= i & -i) {
            for (int j = x; j > 0; j -= j & -j) {
                s += bit[i][j];
            }
        }
        return s;
    }

    int query(int y1, int x1, int y2, int x2) {
        return sum(y2, x2) - sum(y1 - 1, x2) - sum(y2, x1 - 1) + sum(y1 - 1, x1 - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));
    BIT2D bit(n);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char cell;
            cin >> cell;
            if (cell == '*') {
                forest[i][j] = 1;
                bit.update(i, j, 1);
            }
        }
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int y, x;
            cin >> y >> x;
            if (forest[y][x] == 1) {
                bit.update(y, x, -1);
                forest[y][x] = 0;
            } else {
                bit.update(y, x, 1);
                forest[y][x] = 1;
            }
        } else if (type == 2) {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << bit.query(y1, x1, y2, x2) << '\n';
        }
    }

    return 0;
}