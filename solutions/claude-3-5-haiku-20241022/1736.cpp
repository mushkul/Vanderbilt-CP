#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> tree, lazy0, lazy1;
    
    SegTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4*n);
        lazy0.resize(4*n);
        lazy1.resize(4*n);
        build(arr, 1, 0, n-1);
    }
    
    void build(vector<ll>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    void propagate(int node, int start, int end) {
        if (lazy0[node] || lazy1[node]) {
            tree[node] += (end-start+1)*(lazy0[node]) + 
                          ((end-start+1)*(end-start+2)/2)*lazy1[node];
            
            if (start != end) {
                lazy0[2*node] += lazy0[node];
                lazy1[2*node] += lazy1[node];
                lazy0[2*node+1] += lazy0[node] + lazy1[node]*(end-start+1);
                lazy1[2*node+1] += lazy1[node];
            }
            lazy0[node] = lazy1[node] = 0;
        }
    }
    
    void update(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        
        if (start > end || start > r || end < l)
            return;
        
        if (l <= start && end <= r) {
            lazy0[node] += 1;
            lazy1[node] += 1;
            propagate(node, start, end);
            return;
        }
        
        int mid = (start + end) / 2;
        update(2*node, start, mid, l, r);
        update(2*node+1, mid+1, end, l, r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    ll query(int node, int start, int end, int l, int r) {
        if (start > end || start > r || end < l)
            return 0;
        
        propagate(node, start, end);
        
        if (l <= start && end <= r)
            return tree[node];
        
        int mid = (start + end) / 2;
        ll left = query(2*node, start, mid, l, r);
        ll right = query(2*node+1, mid+1, end, l, r);
        return left + right;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    SegTree st(arr);
    
    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        a--; b--;
        
        if (type == 1) {
            st.update(1, 0, n-1, a, b);
        } else {
            cout << st.query(1, 0, n-1, a, b) << "\n";
        }
    }
    
    return 0;
}