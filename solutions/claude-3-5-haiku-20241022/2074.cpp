#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree, arr;
    vector<bool> lazy_rev;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void propagate(int node, int start, int end) {
        if (lazy_rev[node]) {
            int mid = (start + end) / 2;
            swap(tree[2*node], tree[2*node+1]);
            lazy_rev[2*node] ^= 1;
            lazy_rev[2*node+1] ^= 1;
            lazy_rev[node] = false;
        }
    }

    void update_range_rev(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l)
            return;
        
        if (l <= start && end <= r) {
            swap(tree[node], tree[node]);
            lazy_rev[node] ^= 1;
            return;
        }

        propagate(node, start, end);
        int mid = (start + end) / 2;
        update_range_rev(2*node, start, mid, l, r);
        update_range_rev(2*node+1, mid+1, end, l, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    long long query_range_sum(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l)
            return 0;
        
        if (lazy_rev[node]) 
            propagate(node, start, end);

        if (l <= start && end <= r)
            return tree[node];
        
        int mid = (start + end) / 2;
        long long left_sum = query_range_sum(2*node, start, mid, l, r);
        long long right_sum = query_range_sum(2*node+1, mid+1, end, l, r);
        return left_sum + right_sum;
    }

public:
    SegmentTree(vector<long long>& input) {
        n = input.size();
        arr = input;
        tree.resize(4*n);
        lazy_rev.resize(4*n, false);
        build(1, 0, n-1);
    }

    void reverseRange(int l, int r) {
        update_range_rev(1, 0, n-1, l-1, r-1);
    }

    long long rangeSum(int l, int r) {
        return query_range_sum(1, 0, n-1, l-1, r-1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    SegmentTree st(arr);

    while (m--) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 1)
            st.reverseRange(a, b);
        else
            cout << st.rangeSum(a, b) << "\n";
    }

    return 0;
}