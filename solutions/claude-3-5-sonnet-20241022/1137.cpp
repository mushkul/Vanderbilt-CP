#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 2e5+5;
vector<int> adj[MAX_N];
ll val[MAX_N];
int tin[MAX_N], tout[MAX_N];
int timer = 0;
int n, q;

void dfs(int v, int p) {
    tin[v] = timer++;
    for(int u : adj[v]) {
        if(u != p) {
            dfs(u, v);
        }
    }
    tout[v] = timer-1;
}

struct SegTree {
    vector<ll> tree;
    int n;
    
    void init(int sz) {
        n = sz;
        tree.resize(4*n);
    }
    
    void update(int pos, ll val) {
        update(1, 0, n-1, pos, val);
    }
    
    void update(int v, int tl, int tr, int pos, ll val) {
        if(tl == tr) {
            tree[v] = val;
            return;
        }
        int tm = (tl + tr)/2;
        if(pos <= tm)
            update(2*v, tl, tm, pos, val);
        else
            update(2*v+1, tm+1, tr, pos, val);
        tree[v] = tree[2*v] + tree[2*v+1];
    }
    
    ll query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
    
    ll query(int v, int tl, int tr, int l, int r) {
        if(l > r) return 0;
        if(l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr)/2;
        return query(2*v, tl, tm, l, min(r, tm)) +
               query(2*v+1, tm+1, tr, max(l, tm+1), r);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    
    vector<ll> initial(n);
    for(int i = 0; i < n; i++) {
        cin >> initial[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0, -1);
    
    SegTree st;
    st.init(n);
    
    for(int i = 0; i < n; i++) {
        st.update(tin[i], initial[i]);
    }
    
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            st.update(tin[s], x);
        } else {
            int s;
            cin >> s;
            s--;
            cout << st.query(tin[s], tout[s]) << "\n";
        }
    }
    
    return 0;
}