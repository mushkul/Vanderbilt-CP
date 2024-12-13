#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node {
    ll sum = 0;
    ll inc_start = 0;
    ll inc_count = 0;
    ll lazy = 0;
};

class SegTree {
private:
    vector<Node> tree;
    int n;
    
    void push(int node, int start, int end) {
        if(start == end) return;
        int mid = (start + end) / 2;
        int len_left = mid - start + 1;
        int len_right = end - mid;
        
        tree[2*node].sum += tree[node].lazy * len_left;
        tree[2*node].lazy += tree[node].lazy;
        
        tree[2*node+1].sum += tree[node].lazy * len_right;
        tree[2*node+1].lazy += tree[node].lazy;
        
        if(tree[node].inc_count > 0) {
            ll left_start = tree[node].inc_start;
            ll right_start = left_start + len_left;
            
            tree[2*node].sum += (2LL*left_start + len_left-1)*len_left/2LL;
            tree[2*node].inc_start += tree[node].inc_start;
            tree[2*node].inc_count++;
            
            tree[2*node+1].sum += (2LL*right_start + len_right-1)*len_right/2LL;
            tree[2*node+1].inc_start += right_start;
            tree[2*node+1].inc_count++;
        }
        
        tree[node].lazy = 0;
        tree[node].inc_start = 0;
        tree[node].inc_count = 0;
    }
    
    void build(vector<ll>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node].sum = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    }
    
    void update_range(int node, int start, int end, int l, int r) {
        if(start > r || end < l) return;
        
        if(start >= l && end <= r) {
            int len = end - start + 1;
            ll inc_start = start - l + 1;
            tree[node].sum += (2LL*inc_start + len-1)*len/2LL;
            tree[node].inc_start += inc_start;
            tree[node].inc_count++;
            return;
        }
        
        push(node, start, end);
        int mid = (start + end) / 2;
        update_range(2*node, start, mid, l, r);
        update_range(2*node+1, mid+1, end, l, r);
        tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    }
    
    ll query_range(int node, int start, int end, int l, int r) {
        if(start > r || end < l) return 0;
        
        if(start >= l && end <= r) {
            return tree[node].sum;
        }
        
        push(node, start, end);
        int mid = (start + end) / 2;
        return query_range(2*node, start, mid, l, r) + 
               query_range(2*node+1, mid+1, end, l, r);
    }
    
public:
    SegTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }
    
    void update(int l, int r) {
        update_range(1, 0, n-1, l-1, r-1);
    }
    
    ll query(int l, int r) {
        return query_range(1, 0, n-1, l-1, r-1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    SegTree st(arr);
    
    while(q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1) {
            st.update(l, r);
        } else {
            cout << st.query(l, r) << '\n';
        }
    }
    
    return 0;
}