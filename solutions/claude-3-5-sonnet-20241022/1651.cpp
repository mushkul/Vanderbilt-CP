#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll sum = 0;
    ll lazy = 0;
} tree[800005];

ll a[200005];

void build(int node, int start, int end) {
    if(start == end) {
        tree[node].sum = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
}

void propagate(int node, int start, int end) {
    if(tree[node].lazy != 0) {
        tree[node].sum += (end - start + 1) * tree[node].lazy;
        if(start != end) {
            tree[2*node].lazy += tree[node].lazy;
            tree[2*node+1].lazy += tree[node].lazy;
        }
        tree[node].lazy = 0;
    }
}

void update(int node, int start, int end, int l, int r, ll val) {
    propagate(node, start, end);
    if(start > end || start > r || end < l)
        return;
    if(start >= l && end <= r) {
        tree[node].sum += (end - start + 1) * val;
        if(start != end) {
            tree[2*node].lazy += val;
            tree[2*node+1].lazy += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(2*node, start, mid, l, r, val);
    update(2*node+1, mid+1, end, l, r, val);
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
}

ll query(int node, int start, int end, int idx) {
    propagate(node, start, end);
    if(start == end)
        return tree[node].sum;
    int mid = (start + end) / 2;
    if(idx <= mid)
        return query(2*node, start, mid, idx);
    else
        return query(2*node+1, mid+1, end, idx);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    
    build(1, 1, n);
    
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            update(1, 1, n, a, b, u);
        } else {
            int k; cin >> k;
            cout << query(1, 1, n, k) << "\n";
        }
    }
    return 0;
}