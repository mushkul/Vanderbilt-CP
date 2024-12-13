#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int arr[MAXN];
int segTree[4 * MAXN];

void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        segTree[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);
    segTree[node] = min(segTree[2 * node], segTree[2 * node + 1]);
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return INT_MAX;
    if (l <= start && end <= r)
        return segTree[node];
    int mid = (start + end) / 2;
    int left = query(2 * node, start, mid, l, r);
    int right = query(2 * node + 1, mid + 1, end, l, r);
    return min(left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    build(1, 1, n);

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, u;
            cin >> k >> u;
            update(1, 1, n, k, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }

    return 0;
}