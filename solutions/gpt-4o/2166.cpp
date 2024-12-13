#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
public:
    struct Node {
        long long prefixSum, totalSum;
    };
    
    vector<Node> tree;
    int size;
    
    SegmentTree(const vector<int> &arr) {
        size = arr.size();
        tree.resize(4 * size);
        build(arr, 1, 0, size - 1);
    }
    
    void build(const vector<int> &arr, int node, int start, int end) {
        if (start == end) {
            tree[node].prefixSum = tree[node].totalSum = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            merge(node);
        }
    }
    
    void merge(int node) {
        tree[node].totalSum = tree[2 * node].totalSum + tree[2 * node + 1].totalSum;
        tree[node].prefixSum = max(tree[2 * node].prefixSum, tree[2 * node].totalSum + tree[2 * node + 1].prefixSum);
    }
    
    void update(int idx, int value, int node, int start, int end) {
        if (start == end) {
            tree[node].prefixSum = tree[node].totalSum = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(idx, value, 2 * node, start, mid);
            } else {
                update(idx, value, 2 * node + 1, mid + 1, end);
            }
            merge(node);
        }
    }
    
    pair<long long, long long> query(int L, int R, int node, int start, int end) {
        if (L > end || R < start) return {0, 0};
        if (L <= start && end <= R) return {tree[node].prefixSum, tree[node].totalSum};
        
        int mid = (start + end) / 2;
        auto left = query(L, R, 2 * node, start, mid);
        auto right = query(L, R, 2 * node + 1, mid + 1, end);
        
        long long totalSum = left.second + right.second;
        long long prefixSum = max(left.first, left.second + right.first);
        
        return {prefixSum, totalSum};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    
    SegmentTree segTree(arr);
    
    while (q--) {
        int type, x, y;
        cin >> type >> x >> y;
        
        if (type == 1) {
            // Update operation
            segTree.update(x - 1, y, 1, 0, n - 1);
        } else if (type == 2) {
            // Query operation
            auto result = segTree.query(x - 1, y - 1, 1, 0, n - 1);
            cout << result.first << '\n';
        }
    }
    
    return 0;
}