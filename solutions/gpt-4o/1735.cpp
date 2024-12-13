#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int64_t sum, add, set_val;
    bool to_set;
};

class SegmentTree {
public:
    SegmentTree(const vector<int>& arr) : n(arr.size()) {
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    
    void range_add(int l, int r, int x) {
        range_add(0, 0, n - 1, l, r, x);
    }
    
    void range_set(int l, int r, int x) {
        range_set(0, 0, n - 1, l, r, x);
    }
    
    int64_t range_sum(int l, int r) {
        return range_sum(0, 0, n - 1, l, r);
    }

private:
    int n;
    vector<Node> tree;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = {arr[start], 0, 0, false};
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
        }
    }

    void push(int node, int start, int end) {
        if (tree[node].to_set) {
            int64_t val = tree[node].set_val;
            tree[node].sum = val * (end - start + 1);
            if (start != end) {
                tree[2 * node + 1].to_set = true;
                tree[2 * node + 2].to_set = true;
                tree[2 * node + 1].set_val = val;
                tree[2 * node + 2].set_val = val;
                tree[2 * node + 1].add = 0;
                tree[2 * node + 2].add = 0;
            }
            tree[node].add = 0;
            tree[node].to_set = false;
        }
        if (tree[node].add != 0) {
            int64_t add = tree[node].add;
            tree[node].sum += add * (end - start + 1);
            if (start != end) {
                if (!tree[2 * node + 1].to_set)
                    tree[2 * node + 1].add += add;
                else {
                    tree[2 * node + 1].set_val += add;
                    tree[2 * node + 1].add = 0;
                }
                if (!tree[2 * node + 2].to_set)
                    tree[2 * node + 2].add += add;
                else {
                    tree[2 * node + 2].set_val += add;
                    tree[2 * node + 2].add = 0;
                }
            }
            tree[node].add = 0;
        }
    }

    void range_add(int node, int start, int end, int l, int r, int64_t x) {
        push(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node].add += x;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        range_add(2 * node + 1, start, mid, l, r, x);
        range_add(2 * node + 2, mid + 1, end, l, r, x);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }
    
    void range_set(int node, int start, int end, int l, int r, int x) {
        push(node, start, end);
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            tree[node].to_set = true;
            tree[node].set_val = x;
            push(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        range_set(2 * node + 1, start, mid, l, r, x);
        range_set(2 * node + 2, mid + 1, end, l, r, x);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }

    int64_t range_sum(int node, int start, int end, int l, int r) {
        push(node, start, end);
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node].sum;
        int mid = (start + end) / 2;
        return range_sum(2 * node + 1, start, mid, l, r) +
               range_sum(2 * node + 2, mid + 1, end, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int& t : arr) cin >> t;
    SegmentTree st(arr);
    
    while (q--) {
        int type, a, b, x;
        cin >> type >> a >> b;
        --a; --b;
        if (type == 1) {
            cin >> x;
            st.range_add(a, b, x);
        } else if (type == 2) {
            cin >> x;
            st.range_set(a, b, x);
        } else if (type == 3) {
            cout << st.range_sum(a, b) << '\n';
        }
    }
    
    return 0;
}