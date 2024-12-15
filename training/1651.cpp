#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
public:
    FenwickTree(int n) : n(n), data(n + 1, 0) {}

    void add(int idx, long long delta) {
        for (++idx; idx <= n; idx += idx & -idx) {
            data[idx] += delta;
        }
    }

    long long sum(int idx) {
        long long result = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            result += data[idx];
        }
        return result;
    }

private:
    int n;
    vector<long long> data;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    FenwickTree fenwick(n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            fenwick.add(a - 1, u);
            fenwick.add(b, -u);
        } else if (type == 2) {
            int k;
            cin >> k;
            cout << arr[k - 1] + fenwick.sum(k - 1) << '\n';
        }
    }

    return 0;
}