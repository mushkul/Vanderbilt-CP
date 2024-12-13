#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class SegmentTree {
private:
    struct Node {
        ll prefixSum, suffixSum, totalSum, maxSum;
    };
    vector<ll> arr;
    vector<Node> tree;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node].prefixSum = arr[start];
            tree[node].suffixSum = arr[start];
            tree[node].totalSum = arr[start];
            tree[node].maxSum = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        
        tree[node].prefixSum = max(tree[2*node].prefixSum, 
                                   tree[2*node].totalSum + tree[2*node+1].prefixSum);
        tree[node].suffixSum = max(tree[2*node+1].suffixSum, 
                                   tree[2*node+1].totalSum + tree[2*node].suffixSum);
        tree[node].totalSum = tree[2*node].totalSum + tree[2*node+1].totalSum;
        tree[node].maxSum = max({tree[2*node].maxSum, tree[2*node+1].maxSum, 
                                 tree[2*node].suffixSum + tree[2*node+1].prefixSum});
    }

    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) {
            arr[idx] = val;
            tree[node].prefixSum = val;
            tree[node].suffixSum = val;
            tree[node].totalSum = val;
            tree[node].maxSum = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        
        tree[node].prefixSum = max(tree[2*node].prefixSum, 
                                   tree[2*node].totalSum + tree[2*node+1].prefixSum);
        tree[node].suffixSum = max(tree[2*node+1].suffixSum, 
                                   tree[2*node+1].totalSum + tree[2*node].suffixSum);
        tree[node].totalSum = tree[2*node].totalSum + tree[2*node+1].totalSum;
        tree[node].maxSum = max({tree[2*node].maxSum, tree[2*node+1].maxSum, 
                                 tree[2*node].suffixSum + tree[2*node+1].prefixSum});
    }

public:
    SegmentTree(vector<ll>& input) {
        arr = input;
        tree.resize(4*input.size());
        build(1, 0, input.size()-1);
    }

    void updateValue(int idx, ll val) {
        update(1, 0, arr.size()-1, idx, val);
    }

    ll getMaxSubarraySum() {
        return tree[1].maxSum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    SegmentTree st(arr);
    
    while (m--) {
        int k;
        ll x;
        cin >> k >> x;
        st.updateValue(k-1, x);
        cout << st.getMaxSubarraySum() << "\n";
    }
    
    return 0;
}