#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 2e5+5;
ll tree[4*MAX_N];
ll a[MAX_N];

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node, int start, int end, int idx, ll val) {
    if(start == end) {
        a[idx] = val;
        tree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid)
        update(2*node, start, mid, idx, val);
    else
        update(2*node+1, mid+1, end, idx, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int node, int start, int end, int l, int r) {
    if(r < start || end < l)
        return 0;
    if(l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    ll p1 = query(2*node, start, mid, l, r);
    ll p2 = query(2*node+1, mid+1, end, l, r);
    return p1 + p2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++)
        cin >> a[i];
        
    build(1, 1, n);
    
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k;
            ll u;
            cin >> k >> u;
            update(1, 1, n, k, u);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}