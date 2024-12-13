#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
int start[MAXN], endTime[MAXN], flatTree[MAXN];
int BIT[MAXN], values[MAXN];
int timer;

void update(int idx, int val, int n) {
    while (idx <= n) {
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}

void dfs(int node, int par) {
    start[node] = ++timer;
    flatTree[timer] = node;
    for (int child : tree[node]) {
        if (child != par) {
            dfs(child, node);
        }
    }
    endTime[node] = timer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

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
        update(start[i], values[i], n);
    }

    while (q--) {
        int type, s, x;
        cin >> type >> s;
        if (type == 1) {
            cin >> x;
            int diff = x - values[s];
            values[s] = x;
            update(start[s], diff, n);
        } else if (type == 2) {
            cout << query(endTime[s]) - query(start[s] - 1) << '\n';
        }
    }

    return 0;
}