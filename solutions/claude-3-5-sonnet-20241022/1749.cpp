#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int tree[4*N], a[N];
int n;

void build(int node, int start, int end) {
    if(start == end) {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int start, int end, int k) {
    if(start == end) {
        tree[node] = 0;
        return start;
    }
    int mid = (start + end) / 2;
    int ret;
    if(k <= tree[2*node]) {
        ret = query(2*node, start, mid, k);
    }
    else {
        ret = query(2*node+1, mid+1, end, k - tree[2*node]);
    }
    tree[node] = tree[2*node] + tree[2*node+1];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    build(1, 1, n);
    
    for(int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        int idx = query(1, 1, n, pos);
        cout << a[idx] << " ";
    }
    
    return 0;
}