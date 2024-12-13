#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxN = 2e5+5;
ll seg[4*maxN];
ll a[maxN];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2*v, tl, tm);
    build(2*v+1, tm+1, tr);
    seg[v] = min(seg[2*v], seg[2*v+1]);
}

void update(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
        seg[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        update(2*v, tl, tm, pos, val);
    else
        update(2*v+1, tm+1, tr, pos, val);
    seg[v] = min(seg[2*v], seg[2*v+1]);
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 1e18;
    if (l == tl && r == tr)
        return seg[v];
    int tm = (tl + tr) / 2;
    return min(query(2*v, tl, tm, l, min(r, tm)), 
               query(2*v+1, tm+1, tr, max(l, tm+1), r));
}

int main() {
    ios_base::sync_with_stdio(false);
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