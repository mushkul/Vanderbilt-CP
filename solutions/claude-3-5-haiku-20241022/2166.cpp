#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2e5 + 5;
 
struct Node {
    long long maxPrefix;
    long long sum;
};
 
Node tree[4 * MAXN];
long long arr[MAXN];
 
void build(int node, int start, int end) {
    if (start == end) {
        tree[node].maxPrefix = max(0LL, arr[start]);
        tree[node].sum = arr[start];
        return;
    }
 
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
 
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    tree[node].maxPrefix = max(tree[2 * node].maxPrefix,
                               tree[2 * node].sum + tree[2 * node + 1].maxPrefix);
}
 
void update(int node, int start, int end, int idx, long long val) {
    if (start == end) {
        arr[idx] = val;
        tree[node].maxPrefix = max(0LL, val);
        tree[node].sum = val;
        return;
    }
 
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);
 
    tree[node].sum = tree[2 * node].sum + tree[2 * node + 1].sum;
    tree[node].maxPrefix = max(tree[2 * node].maxPrefix,
                               tree[2 * node].sum + tree[2 * node + 1].maxPrefix);
}
 
Node query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return {0, 0};
 
    if (left <= start && end <= right)
        return tree[node];
 
    int mid = (start + end) / 2;
    Node leftNode = query(2 * node, start, mid, left, right);
    Node rightNode = query(2 * node + 1, mid + 1, end, left, right);
 
    Node result;
    result.sum = leftNode.sum + rightNode.sum;
    result.maxPrefix = max(leftNode.maxPrefix, leftNode.sum + rightNode.maxPrefix);
    return result;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin >> n >> q;
 
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
 
    build(1, 1, n);
 
    while (q--) {
        int t, a, b;
        cin >> t;
 
        if (t == 1) {
            cin >> a >> b;
            update(1, 1, n, a, b);
        } else {
            cin >> a >> b;
            Node result = query(1, 1, n, a, b);
            cout << result.maxPrefix << '\n';
        }
    }
 
    return 0;
}