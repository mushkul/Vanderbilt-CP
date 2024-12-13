#include <bits/stdc++.h>
using namespace std;
 
struct SegmentTree {
    vector<long long> tree;
    vector<long long> arr;
    
    SegmentTree(vector<long long>& nums) {
        arr = nums;
        tree.resize(4 * nums.size());
        build(1, 0, nums.size() - 1);
    }
    
    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    void update(int node, int start, int end, int idx, long long val) {
        if (start == end) {
            tree[node] = val;
            arr[idx] = val;
            return;
        }
        
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    
    long long query(int node, int start, int end, int left, int right) {
        if (right < start || left > end)
            return 0;
        
        if (left <= start && end <= right)
            return tree[node];
        
        int mid = (start + end) / 2;
        long long leftSum = query(2 * node, start, mid, left, right);
        long long rightSum = query(2 * node + 1, mid + 1, end, left, right);
        
        return leftSum + rightSum;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<SegmentTree> trees;
    trees.push_back(SegmentTree(nums));
    
    while (q--) {
        int type, k, a, b, x;
        cin >> type;
        
        if (type == 1) {
            cin >> k >> a >> x;
            k--;
            trees[k].update(1, 0, n - 1, a - 1, x);
        }
        else if (type == 2) {
            cin >> k >> a >> b;
            k--;
            cout << trees[k].query(1, 0, n - 1, a - 1, b - 1) << "\n";
        }
        else {
            cin >> k;
            k--;
            trees.push_back(trees[k]);
        }
    }
    
    return 0;
}