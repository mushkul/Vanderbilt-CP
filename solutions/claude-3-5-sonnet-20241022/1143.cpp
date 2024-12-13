#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegmentTree {
    vector<ll> tree;
    int n;
    
    SegmentTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4*n);
        build(arr, 1, 0, n-1);
    }
    
    void build(vector<ll>& arr, int node, int start, int end) {
        if(start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end)/2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
    
    void update(int node, int start, int end, int idx, ll val) {
        if(start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end)/2;
        if(idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
    
    int query(int node, int start, int end, ll val) {
        if(tree[node] < val) return 0;
        if(start == end) return start+1;
        int mid = (start + end)/2;
        if(tree[2*node] >= val)
            return query(2*node, start, mid, val);
        else
            return query(2*node+1, mid+1, end, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<ll> hotels(n);
    for(int i = 0; i < n; i++) {
        cin >> hotels[i];
    }
    
    SegmentTree st(hotels);
    
    for(int i = 0; i < m; i++) {
        ll rooms;
        cin >> rooms;
        int hotel = st.query(1, 0, n-1, rooms);
        cout << hotel << " ";
        if(hotel > 0) {
            hotels[hotel-1] -= rooms;
            st.update(1, 0, n-1, hotel-1, hotels[hotel-1]);
        }
    }
    
    return 0;
}