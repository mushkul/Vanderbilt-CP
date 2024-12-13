#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    ll sum, pref, suff, ans;
    Node() : sum(0), pref(0), suff(0), ans(0) {}
    Node(ll val) {
        sum = val;
        pref = suff = ans = max(0LL, val);
    }
};

const int MAXN = 2e5+5;
Node tree[4*MAXN];
ll arr[MAXN];

Node combine(Node l, Node r) {
    Node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max({0LL, l.ans, r.ans, l.suff + r.pref});
    return res;
}

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = Node(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = combine(tree[2*node], tree[2*node+1]);
}

void update(int node, int start, int end, int idx, ll val) {
    if(start == end) {
        tree[node] = Node(val);
        arr[idx] = val;
        return;
    }
    int mid = (start + end) / 2;
    if(idx <= mid)
        update(2*node, start, mid, idx, val);
    else
        update(2*node+1, mid+1, end, idx, val);
    tree[node] = combine(tree[2*node], tree[2*node+1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
        
    build(1, 1, n);
    
    while(m--) {
        int k;
        ll x;
        cin >> k >> x;
        update(1, 1, n, k, x);
        cout << tree[1].ans << "\n";
    }
    
    return 0;
}