#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    ll sum, pref;
};

const int MAX_N = 2e5+5;
Node tree[4*MAX_N];
ll arr[MAX_N];

Node combine(Node a, Node b) {
    Node c;
    c.sum = a.sum + b.sum;
    c.pref = max(a.pref, a.sum + b.pref);
    return c;
}

void build(int node, int start, int end) {
    if(start == end) {
        tree[node].sum = arr[start];
        tree[node].pref = max(0LL, arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = combine(tree[2*node], tree[2*node+1]);
}

void update(int node, int start, int end, int idx, ll val) {
    if(start == end) {
        arr[idx] = val;
        tree[node].sum = val;
        tree[node].pref = max(0LL, val);
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid)
        update(2*node, start, mid, idx, val);
    else
        update(2*node+1, mid+1, end, idx, val);
    tree[node] = combine(tree[2*node], tree[2*node+1]);
}

Node query(int node, int start, int end, int l, int r) {
    if(r < start || end < l) {
        return {0, 0};
    }
    if(l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return combine(query(2*node, start, mid, l, r), 
                  query(2*node+1, mid+1, end, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    build(1, 1, n);
    
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k;
            ll u;
            cin >> k >> u;
            update(1, 1, n, k, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b).pref << "\n";
        }
    }
    
    return 0;
}