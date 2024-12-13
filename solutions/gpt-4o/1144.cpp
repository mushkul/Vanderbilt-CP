#include <bits/stdc++.h>
using namespace std;

// Segment Tree implementation for range frequency queries
class SegmentTree {
    vector<int> st;
    int n;

    void build(int node, int l, int r, const vector<int> &arr) {
        if (l == r) {
            st[node] = arr[l];
        } else {
            int mid = (l + r) / 2;
            build(2*node+1, l, mid, arr);
            build(2*node+2, mid+1, r, arr);
            st[node] = st[2*node+1] | st[2*node+2];
        }
    }
    
    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            st[node] = value;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid) update(2*node+1, l, mid, idx, value);
            else update(2*node+2, mid+1, r, idx, value);
            st[node] = st[2*node+1] | st[2*node+2];
        }
    }
    
    int query(int node, int l, int r, int L, int R, int mask) {
        if (r < L || R < l) return 0;
        if (L <= l && r <= R) return __builtin_popcount(st[node] & mask);
        int mid = (l + r) / 2;
        return query(2*node+1, l, mid, L, R, mask) + query(2*node+2, mid+1, r, L, R, mask);
    }

    int getSalaryMask(int salary, map<int, int> &salaryMap) {
        int mask = 0;
        for (auto &[val, bit] : salaryMap) {
            if (val > salary) break;
            mask |= (1 << bit);
        }
        return mask;
    }

public:
    SegmentTree(const vector<int> &arr, map<int, int> &salaryMap) : n(arr.size()) {
        st.resize(4 * n, 0);
        vector<int> masks(n);
        for (int i = 0; i < n; ++i) {
            masks[i] = getSalaryMask(arr[i], salaryMap);
        }
        build(0, 0, n-1, masks);
    }

    void update(int idx, int value, map<int, int> &salaryMap) {
        update(0, 0, n-1, idx, getSalaryMask(value, salaryMap));
    }

    int query(int L, int R, int mask) {
        return query(0, 0, n-1, L, R, mask);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> salaries(n);
    for (int i = 0; i < n; ++i) cin >> salaries[i];

    set<int> uniqueSalaries(salaries.begin(), salaries.end());
    map<int, int> salaryMap;
    int bit = 0;
    for (auto val : uniqueSalaries) {
        salaryMap[val] = bit++;
    }

    SegmentTree segTree(salaries, salaryMap);

    while (q--) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            segTree.update(k-1, x, salaryMap);
            if (salaryMap.find(x) == salaryMap.end()) {
                salaryMap[x] = bit++;
            }
        } else if (type == '?') {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            auto itLow = salaryMap.lower_bound(a);
            auto itHigh = salaryMap.upper_bound(b);
            int mask = 0;
            for (auto it = itLow; it != itHigh; ++it) {
                mask |= (1 << it->second);
            }
            cout << segTree.query(0, n-1, mask) << '\n';
        }
    }

    return 0;
}