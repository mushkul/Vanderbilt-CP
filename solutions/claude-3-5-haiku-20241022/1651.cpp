#include <bits/stdc++.h>
using namespace std;
 
struct FenwickTree {
    vector<long long> bit;
    int n;
 
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }
 
    void update(int index, long long val) {
        while (index <= n) {
            bit[index] += val;
            index += index & -index;
        }
    }
 
    void range_update(int l, int r, long long val) {
        update(l, val);
        update(r + 1, -val);
    }
 
    long long query(int index) {
        long long sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & -index;
        }
        return sum;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n, q;
    cin >> n >> q;
 
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
 
    FenwickTree ft(n);
    for (int i = 1; i <= n; i++) {
        ft.range_update(i, i, arr[i]);
    }
 
    while (q--) {
        int type;
        cin >> type;
 
        if (type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            ft.range_update(a, b, u);
        } else {
            int k;
            cin >> k;
            cout << ft.query(k) << '\n';
        }
    }
 
    return 0;
}