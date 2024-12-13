#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<long long> bit;
    int n;
    
public:
    FenwickTree(int size) : n(size) {
        bit.assign(n + 1, 0);
    }
    
    void update(int idx, long long delta) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }
    
    long long sum(int idx) {
        long long result = 0;
        for (; idx > 0; idx -= idx & -idx) {
            result += bit[idx];
        }
        return result;
    }
    
    long long range_sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n + 1);
    FenwickTree fenwickTree(n);
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        fenwickTree.update(i, arr[i]);
    }
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            fenwickTree.update(k, u - arr[k]);
            arr[k] = u;
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << fenwickTree.range_sum(a, b) << '\n';
        }
    }
    
    return 0;
}