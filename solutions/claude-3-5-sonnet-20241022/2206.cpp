#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    vector<ll> tree;
    int n;

    SegTree(int _n) {
        n = _n;
        tree.resize(4*n);
    }

    void update(int node, int start, int end, int idx, ll val) {
        if(start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        if(idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);

        tree[node] = min(tree[2*node], tree[2*node+1]);
    }

    ll query(int node, int start, int end, int l, int r) {
        if(l > end || r < start)
            return LLONG_MAX;
        if(l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;
        ll left = query(2*node, start, mid, l, r);
        ll right = query(2*node+1, mid+1, end, l, r);
        return min(left, right);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    SegTree left(n+1), right(n+1);
    
    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        left.update(1, 1, n, i, x + i);
        right.update(1, 1, n, i, x - i);
    }

    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k;
            ll x;
            cin >> k >> x;
            left.update(1, 1, n, k, x + k);
            right.update(1, 1, n, k, x - k);
        } else {
            int k;
            cin >> k;
            ll ans = LLONG_MAX;
            ll l = left.query(1, 1, n, 1, k);
            ll r = right.query(1, 1, n, k, n);
            ans = min({ans, l - k, r + k});
            cout << ans << '\n';
        }
    }
    return 0;
}