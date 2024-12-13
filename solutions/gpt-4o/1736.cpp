#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
public:
    FenwickTree(int size) : tree(size + 1, 0) {}

    void update(int idx, long long delta) {
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += idx & (-idx);
        }
    }

    long long query(int idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

private:
    vector<long long> tree;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> t(n + 1), d(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i];
    }

    FenwickTree mainTree(n), incTree(n);

    for (int i = 1; i <= n; ++i) {
        mainTree.update(i, t[i]);
    }

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 1) {
            incTree.update(a, 1);
            if (b + 1 <= n) {
                incTree.update(b + 1, -(b - a + 2));
            }
            long long delta = a - 1;
            mainTree.update(a, -delta);
            if (b + 1 <= n) {
                mainTree.update(b + 1, delta + (b - a + 2) * (b + 1));
            }
        } else {
            long long incSum = incTree.query(b) * b - incTree.query(a - 1) * (a - 1);
            long long mainSum = mainTree.query(b) - mainTree.query(a - 1);
            cout << incSum + mainSum << '\n';
        }
    }

    return 0;
}