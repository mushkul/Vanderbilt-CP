#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 5;

struct Node {
    ll sum;
    Node *left, *right;
    Node(ll v = 0) : sum(v), left(nullptr), right(nullptr) {}
    Node(Node* l, Node* r) : left(l), right(r) {
        sum = l->sum + r->sum;
    } 
};

Node* build(int l, int r, vector<ll>& a) {
    if(l == r)
        return new Node(a[l]);
    int m = (l + r) >> 1;
    return new Node(build(l, m, a), build(m+1, r, a));
}

Node* update(Node* node, int l, int r, int pos, ll val) {
    if(l == r)
        return new Node(val);
    int m = (l + r) >> 1;
    if(pos <= m)
        return new Node(update(node->left, l, m, pos, val), node->right);
    else
        return new Node(node->left, update(node->right, m+1, r, pos, val));
}

ll query(Node* node, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr)
        return node->sum;
    if(qr < l || r < ql)
        return 0;
    int m = (l + r) >> 1;
    return query(node->left, l, m, ql, qr) + query(node->right, m+1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
        
    vector<Node*> versions;
    versions.push_back(build(1, n, a));
    
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int k, pos;
            ll x;
            cin >> k >> pos >> x;
            versions[k-1] = update(versions[k-1], 1, n, pos, x);
        }
        else if(type == 2) {
            int k, l, r;
            cin >> k >> l >> r;
            cout << query(versions[k-1], 1, n, l, r) << '\n';
        }
        else {
            int k;
            cin >> k;
            versions.push_back(versions[k-1]);
        }
    }
    
    return 0;
}