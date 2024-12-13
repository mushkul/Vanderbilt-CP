#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class FenwickTree {
private:
    vector<ll> tree;
    int size;

public:
    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }

    void update(int index, ll value) {
        while (index <= size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    ll query(int index) {
        ll sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= index & -index;
        }
        return sum;
    }

    ll rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    FenwickTree ft(n);
    for (int i = 1; i <= n; i++) {
        ft.update(i, arr[i]);
    }

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int k, u;
            cin >> k >> u;
            ll diff = u - arr[k];
            arr[k] = u;
            ft.update(k, diff);
        } else {
            int a, b;
            cin >> a >> b;
            cout << ft.rangeQuery(a, b) << "\n";
        }
    }

    return 0;
}