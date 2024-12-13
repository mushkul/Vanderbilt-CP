#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<int> segTree(4*n);
    
    function<void(int, int, int)> build = [&](int node, int start, int end) {
        if (start == end) {
            segTree[node] = arr[start];
            return;
        }
        
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        
        segTree[node] = min(segTree[2*node], segTree[2*node+1]);
    };
    
    function<int(int, int, int, int, int)> query = [&](int node, int start, int end, int left, int right) {
        if (start > right || end < left) return INT_MAX;
        
        if (left <= start && end <= right) return segTree[node];
        
        int mid = (start + end) / 2;
        int leftMin = query(2*node, start, mid, left, right);
        int rightMin = query(2*node+1, mid+1, end, left, right);
        
        return min(leftMin, rightMin);
    };
    
    build(1, 0, n-1);
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << query(1, 0, n-1, a-1, b-1) << endl;
    }
    
    return 0;
}