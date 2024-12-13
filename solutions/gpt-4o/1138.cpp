#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> tree[MAXN];
int values[MAXN];
int parent[MAXN];
int tin[MAXN];
int tout[MAXN];
int timer;
long long segtree[4 * MAXN];
long long lazy[4 * MAXN];

void dfs(int node, int par) {
    parent[node] = par;
    tin[node] = ++timer;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
    tout[node] = timer;
}

void propagate(int node, int start, int end) {
    if (lazy[node] != 0) {
        segtree[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void build(int node, int start, int end) {
    if (start == end) {
        segtree[node] = values[start];
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
    }
}

void update(int node, int start, int end, int l, int r, long long value) {
    propagate(node, start, end);
    if (start > end || start > r || end < l) {
        return;
    }
    if (start >= l && end <= r) {
        segtree[node] += value * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, l, r, value);
    update(node * 2 + 1, mid + 1, end, l, r, value);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

long long query(int node, int start, int end, int l, int r) {
    propagate(node, start, end);
    if (start > end || start > r || end < l) {
        return 0;
    }
    if (start >= l && end <= r) {
        return segtree[node];
    }
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    timer = 0;
    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        values[tin[i]] = values[i];
    }

    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            int diff = x - values[tin[s]];
            values[tin[s]] = x;
            update(1, 1, n, tin[s], tin[s], diff);
        } else if (type == 2) {
            int s;
            cin >> s;
            cout << query(1, 1, n, 1, tin[s]) << "\n";
        }
    }

    return 0;
}