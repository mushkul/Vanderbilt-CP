#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int size;

    void build(vector<long long>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    void update(int node, int start, int end, int index, long long val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            update(2*node, start, mid, index, val);
        else
            update(2*node+1, mid+1, end, index, val);
        tree[node] = max(tree[2*node], tree[2*node+1]);
    }

    int query(int node, int start, int end, int left, int right, long long rooms) {
        if (start == end) {
            return (tree[node] >= rooms) ? start : 0;
        }
        int mid = (start + end) / 2;
        if (tree[2*node] >= rooms && left <= mid)
            return query(2*node, start, mid, left, right, rooms);
        else if (tree[2*node+1] >= rooms && right > mid)
            return query(2*node+1, mid+1, end, left, right, rooms);
        return 0;
    }

public:
    SegmentTree(vector<long long>& arr) {
        size = arr.size();
        tree.resize(4 * size);
        build(arr, 1, 0, size - 1);
    }

    void updateValue(int index, long long val) {
        update(1, 0, size - 1, index, val);
    }

    int findHotel(long long rooms) {
        return query(1, 0, size - 1, 0, size - 1, rooms);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> hotels(n);
    for (int i = 0; i < n; i++) {
        cin >> hotels[i];
    }

    SegmentTree st(hotels);

    for (int i = 0; i < m; i++) {
        long long group;
        cin >> group;

        int hotel = st.findHotel(group);
        cout << hotel << " ";

        if (hotel != 0) {
            hotels[hotel-1] -= group;
            st.updateValue(hotel-1, hotels[hotel-1]);
        }
    }

    return 0;
}