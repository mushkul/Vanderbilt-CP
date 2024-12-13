#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SegmentTree {
private:
    int n;
    vector<ll> tree, lazy_add, lazy_set;

    void propagate(int node, int start, int end) {
        if (lazy_set[node] != LLONG_MAX) {
            tree[node] = lazy_set[node] * (end - start + 1);
            lazy_add[node] = 0;
            if (start != end) {
                lazy_set[node * 2] = lazy_set[node];
                lazy_set[node * 2 + 1] = lazy_set[node];
            }
            lazy_set[node] = LLONG_MAX;
        }

        if (lazy_add[node] != 0) {
            tree[node] += lazy_add[node] * (end - start + 1);
            if (start != end) {
                lazy_add[node * 2] += lazy_add[node];
                lazy_add[node * 2 + 1] += lazy_add[node];
            }
            lazy_add[node] = 0;
        }
    }

    void update_range_add(int node, int start, int end, int l, int r, ll value) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) return;
        if (l <= start && end <= r) {
            lazy_add[node] += value;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_range_add(node * 2, start, mid, l, r, value);
        update_range_add(node * 2 + 1, mid + 1, end, l, r, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    void update_range_set(int node, int start, int end, int l, int r, ll value) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) return;
        if (l <= start && end <= r) {
            lazy_set[node] = value;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        update_range_set(node * 2, start, mid, l, r, value);
        update_range_set(node * 2 + 1, mid + 1, end, l, r, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    ll query_range_sum(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l) return 0;
        propagate(node, start, end);
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query_range_sum(node * 2, start, mid, l, r) + 
               query_range_sum(node * 2 + 1, mid + 1, end, l, r);
    }

    void build(int node, int start, int end, vector<ll>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(node * 2, start, mid, arr);
        build(node * 2 + 1, mid + 1, end, arr);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

public:
    SegmentTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        lazy_add.resize(4 * n, 0);
        lazy_set.resize(4 * n, LLONG_MAX);
        build(1, 0, n - 1, arr);
    }

    void range_add(int l, int r, ll value) {
        update_range_add(1, 0, n - 1, l, r, value);
    }

    void range_set(int l, int r, ll value) {
        update_range_set(1, 0, n - 1, l, r, value);
    }

    ll range_sum(int l, int r) {
        return query_range_sum(1, 0, n - 1, l, r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree st(arr);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        a--; b--;

        if (type == 1) {
            ll x;
            cin >> x;
            st.range_add(a, b, x);
        } else if (type == 2) {
            ll x;
            cin >> x;
            st.range_set(a, b, x);
        } else {
            cout << st.range_sum(a, b) << "\n";
        }
    }

    return 0;
}