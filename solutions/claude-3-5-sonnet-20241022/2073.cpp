#include <bits/stdc++.h>
using namespace std;

struct Node {
    int prior, size;
    char val;
    Node *l, *r;
    bool rev;
    Node(char val) : prior(rand()), size(1), val(val), l(NULL), r(NULL), rev(false) {}
};

int get_size(Node* t) {
    return t ? t->size : 0;
}

void update_size(Node* t) {
    if (t) t->size = get_size(t->l) + 1 + get_size(t->r);
}

void push(Node* t) {
    if (t && t->rev) {
        t->rev = false;
        swap(t->l, t->r);
        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
    }
}

void split(Node* t, Node*& l, Node*& r, int pos, int add = 0) {
    if (!t) return void(l = r = NULL);
    push(t);
    int curr_pos = add + get_size(t->l);
    if (curr_pos < pos) {
        split(t->r, t->r, r, pos, curr_pos + 1);
        l = t;
    } else {
        split(t->l, l, t->l, pos, add);
        r = t;
    }
    update_size(t);
}

Node* merge(Node* l, Node* r) {
    push(l);
    push(r);
    if (!l || !r) return l ? l : r;
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        update_size(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update_size(r);
        return r;
    }
}

void reverse(Node*& t, int l, int r) {
    Node *t1, *t2, *t3;
    split(t, t1, t2, l);
    split(t2, t2, t3, r - l + 1);
    t2->rev ^= true;
    t = merge(t1, merge(t2, t3));
}

void print(Node* t) {
    if (!t) return;
    push(t);
    print(t->l);
    cout << t->val;
    print(t->r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    
    Node* root = NULL;
    for (char c : s) {
        root = merge(root, new Node(c));
    }
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        reverse(root, l-1, r-1);
    }
    
    print(root);
    cout << "\n";
    
    return 0;
}