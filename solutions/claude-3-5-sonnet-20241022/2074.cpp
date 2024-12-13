#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
struct node {
    ll sum, rev;
    node *l, *r;
    int size;
    ll val;
    node(ll v = 0) {
        sum = val = v;
        rev = 0;
        l = r = NULL;
        size = 1;
    }
};
 
int getsz(node *t) {
    return t ? t->size : 0;
}
 
ll getsum(node *t) {
    return t ? t->sum : 0;
}
 
void push(node *t) {
    if (!t || !t->rev) return;
    swap(t->l, t->r);
    if (t->l) t->l->rev ^= 1;
    if (t->r) t->r->rev ^= 1;
    t->rev = 0;
}
 
void update(node *t) {
    if (!t) return;
    t->size = getsz(t->l) + 1 + getsz(t->r);
    t->sum = getsum(t->l) + t->val + getsum(t->r);
}
 
void split(node *t, node *&l, node *&r, int pos, int add = 0) {
    if (!t) {
        l = r = NULL;
        return;
    }
    push(t);
    int curr = add + getsz(t->l);
    if (curr < pos) {
        split(t->r, t->r, r, pos, curr + 1);
        l = t;
    } else {
        split(t->l, l, t->l, pos, add);
        r = t;
    }
    update(t);
}
 
node *merge(node *l, node *r) {
    if (!l) return r;
    if (!r) return l;
    push(l);
    push(r);
    if (rand() % (l->size + r->size) < l->size) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    node *root = NULL;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        root = merge(root, new node(x));
    }
    
    while (m--) {
        int t, a, b;
        cin >> t >> a >> b;
        node *l, *mid, *r;
        split(root, l, mid, a-1);
        split(mid, mid, r, b-a+1);
        
        if (t == 1) {
            mid->rev ^= 1;
        } else {
            cout << mid->sum << "\n";
        }
        
        root = merge(l, merge(mid, r));
    }
}