#include <bits/stdc++.h>
using namespace std;

class FenwickTree2D {
private:
    vector<vector<int>> tree;
    int n;

public:
    FenwickTree2D(int size) : n(size), tree(size + 1, vector<int>(size + 1, 0)) {}

    void update(int r, int c, int val) {
        for (int i = r; i <= n; i += i & -i) {
            for (int j = c; j <= n; j += j & -j) {
                tree[i][j] += val;
            }
        }
    }

    int query(int r, int c) {
        int sum = 0;
        for (int i = r; i > 0; i -= i & -i) {
            for (int j = c; j > 0; j -= j & -j) {
                sum += tree[i][j];
            }
        }
        return sum;
    }

    int rangeQuery(int r1, int c1, int r2, int c2) {
        return query(r2, c2) - query(r2, c1 - 1) 
               - query(r1 - 1, c2) + query(r1 - 1, c1 - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    FenwickTree2D ft(n);
    
    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++) {
            if (row[j-1] == '*') {
                ft.update(i, j, 1);
            }
        }
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int y, x;
            cin >> y >> x;
            
            int current = ft.rangeQuery(y, x, y, x);
            ft.update(y, x, current == 1 ? -1 : 1);
        }
        else {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            
            cout << ft.rangeQuery(y1, x1, y2, x2) << "\n";
        }
    }

    return 0;
}