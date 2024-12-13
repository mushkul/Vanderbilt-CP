#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+5;
int n, q;
vector<int> adj[N];
vector<int> val;
int up[20][N], depth[N], st[4*N], lazy[4*N], in[N], out[N], t;

void dfs(int u, int p) {
    in[u] = ++t;
    up[0][u] = p;
    for(int i = 1; i < 20; i++) {
        up[i][u] = up[i-1][up[i-1][u]];
    }
    for(int v : adj[u]) {
        if(v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
    out[u] = t;
}

void build(int node, int start, int end) {
    if(start == end) {
        st[node] = val[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    st[node] = max(st[2*node], st[2*node+1]);
}

void update(int node, int start, int end, int l, int r, int val) {
    if(lazy[node] != 0) {
        st[node] = lazy[node];
        if(start != end) {
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > end || start > r || end < l)
        return;
    if(start >= l && end <= r) {
        st[node] = val;
        if(start != end) {
            lazy[2*node] = val;
            lazy[2*node+1] = val;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(2*node, start, mid, l, r, val);
    update(2*node+1, mid+1, end, l, r, val);
    st[node] = max(st[2*node], st[2*node+1]);
}

int query(int node, int start, int end, int l, int r) {
    if(start > end || start > r || end < l)
        return 0;
    if(lazy[node] != 0) {
        st[node] = lazy[node];
        if(start != end) {
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l && end <= r)
        return st[node];
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return max(p1, p2);
}

int lca(int a, int b) {
    if(depth[a] < depth[b])
        swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = 19; i >= 0; i--) {
        if(k & (1<<i))
            a = up[i][a];
    }
    if(a == b)
        return a;
    for(int i = 19; i >= 0; i--) {
        if(up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    val.resize(n+1);
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 1);
    vector<int> temp(n+1);
    for(int i = 1; i <= n; i++) {
        temp[in[i]] = val[i];
    }
    val = temp;
    build(1, 1, n);
    
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            int s, x;
            cin >> s >> x;
            update(1, 1, n, in[s], in[s], x);
        }
        else {
            int a, b;
            cin >> a >> b;
            int l = lca(a, b);
            int ans = max(query(1, 1, n, in[l], in[a]), query(1, 1, n, in[l], in[b]));
            cout << ans << "\n";
        }
    }
    
    return 0;
}