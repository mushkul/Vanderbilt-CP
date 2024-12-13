#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> graph[MAXN];
int values[MAXN], start[MAXN], en[MAXN], flat[MAXN], subtree_size[MAXN];
int timer = 0;

void dfs(int node, int parent) {
    start[node] = ++timer;
    flat[timer] = node;
    subtree_size[node] = 1;
    
    for (int child : graph[node]) {
        if (child != parent) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
    
    en[node] = timer;
}

struct FenwickTree {
    vector<long long> tree;
    int n;
    
    FenwickTree(int size) {
        n = size;
        tree.resize(n + 1, 0);
    }
    
    void update(int pos, int val) {
        while (pos <= n) {
            tree[pos] += val;
            pos += pos & -pos;
        }
    }
    
    long long query(int pos) {
        long long sum = 0;
        while (pos > 0) {
            sum += tree[pos];
            pos -= pos & -pos;
        }
        return sum;
    }
    
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i) {
        cin >> values[i];
    }
    
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1, 0);
    
    FenwickTree ft(n);
    
    for (int i = 1; i <= n; ++i) {
        ft.update(start[i], values[i]);
    }
    
    while (q--) {
        int t, s, x;
        cin >> t;
        
        if (t == 1) {
            cin >> s >> x;
            ft.update(start[s], x - values[s]);
            values[s] = x;
        } else {
            cin >> s;
            cout << ft.rangeQuery(start[s], en[s]) << "\n";
        }
    }
    
    return 0;
}