#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll sum = 0, lazy_add = 0;
    bool has_set = false;
    ll set_val = 0;
    
    void reset() {
        lazy_add = 0;
        has_set = false;
        set_val = 0;
    }
};

struct SegTree {
    int n;
    vector<Node> tree;
    
    SegTree(int _n) : n(_n) {
        tree.resize(4 * n);
    }
    
    void build(int node, int start, int end, vector<int>& arr) {
        if(start == end) {
            tree[node].sum = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2*node, start, mid, arr);
        build(2*node+1, mid+1, end, arr);
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    }
    
    void push_down(int node, int start, int end) {
        if(start == end) return;
        
        int mid = (start + end) / 2;
        int left = 2*node;
        int right = 2*node+1;
        
        if(tree[node].has_set) {
            tree[left].has_set = tree[right].has_set = true;
            tree[left].set_val = tree[right].set_val = tree[node].set_val;
            tree[left].lazy_add = tree[right].lazy_add = 0;
            tree[left].sum = tree[node].set_val * (mid - start + 1);
            tree[right].sum = tree[node].set_val * (end - mid);
        }
        
        if(tree[node].lazy_add != 0) {
            if(tree[left].has_set) {
                tree[left].set_val += tree[node].lazy_add;
                tree[left].sum = tree[left].set_val * (mid - start + 1);
            } else {
                tree[left].lazy_add += tree[node].lazy_add;
                tree[left].sum += tree[node].lazy_add * (mid - start + 1);
            }
            
            if(tree[right].has_set) {
                tree[right].set_val += tree[node].lazy_add;
                tree[right].sum = tree[right].set_val * (end - mid);
            } else {
                tree[right].lazy_add += tree[node].lazy_add;
                tree[right].sum += tree[node].lazy_add * (end - mid);
            }
        }
        
        tree[node].reset();
    }
    
    void set_range(int node, int start, int end, int l, int r, int val) {
        if(start > r || end < l) return;
        
        if(l <= start && end <= r) {
            tree[node].has_set = true;
            tree[node].set_val = val;
            tree[node].lazy_add = 0;
            tree[node].sum = val * (end - start + 1);
            return;
        }
        
        push_down(node, start, end);
        
        int mid = (start + end) / 2;
        set_range(2*node, start, mid, l, r, val);
        set_range(2*node+1, mid+1, end, l, r, val);
        
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    }
    
    void add_range(int node, int start, int end, int l, int r, int val) {
        if(start > r || end < l) return;
        
        if(l <= start && end <= r) {
            if(tree[node].has_set) {
                tree[node].set_val += val;
                tree[node].sum = tree[node].set_val * (end - start + 1);
            } else {
                tree[node].lazy_add += val;
                tree[node].sum += val * (end - start + 1);
            }
            return;
        }
        
        push_down(node, start, end);
        
        int mid = (start + end) / 2;
        add_range(2*node, start, mid, l, r, val);
        add_range(2*node+1, mid+1, end, l, r, val);
        
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    }
    
    ll query_range(int node, int start, int end, int l, int r) {
        if(start > r || end < l) return 0;
        
        if(l <= start && end <= r) {
            return tree[node].sum;
        }
        
        push_down(node, start, end);
        
        int mid = (start + end) / 2;
        return query_range(2*node, start, mid, l, r) + 
               query_range(2*node+1, mid+1, end, l, r);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    SegTree st(n);
    st.build(1, 0, n-1, arr);
    
    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            st.add_range(1, 0, n-1, a-1, b-1, x);
        }
        else if(type == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            st.set_range(1, 0, n-1, a-1, b-1, x);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << st.query_range(1, 0, n-1, a-1, b-1) << '\n';
        }
    }
    
    return 0;
}