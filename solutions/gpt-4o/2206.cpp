#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1e18;

class SegmentTree {
private:
    int n;
    vector<long long> mini1, mini2;

    void build(int idx, int left, int right, const vector<int>& prices) {
        if (left == right) {
            mini1[idx] = prices[left] + left;
            mini2[idx] = prices[left] - left;
            return;
        }
        int mid = (left + right) / 2;
        build(2 * idx + 1, left, mid, prices);
        build(2 * idx + 2, mid + 1, right, prices);
        mini1[idx] = min(mini1[2 * idx + 1], mini1[2 * idx + 2]);
        mini2[idx] = min(mini2[2 * idx + 1], mini2[2 * idx + 2]);
    }

    // Queries for mini1, which stores prices[i] + i
    long long query1(int idx, int left, int right, int ql, int qr) {
        if (qr < left || ql > right) return INF;
        if (ql <= left && qr >= right) return mini1[idx];
        int mid = (left + right) / 2;
        return min(query1(2 * idx + 1, left, mid, ql, qr),
                   query1(2 * idx + 2, mid + 1, right, ql, qr));
    }

    // Queries for mini2, which stores prices[i] - i
    long long query2(int idx, int left, int right, int ql, int qr) {
        if (qr < left || ql > right) return INF;
        if (ql <= left && qr >= right) return mini2[idx];
        int mid = (left + right) / 2;
        return min(query2(2 * idx + 1, left, mid, ql, qr),
                   query2(2 * idx + 2, mid + 1, right, ql, qr));
    }

    void update(int idx, int left, int right, int pos, int value) {
        if (left == right) {
            mini1[idx] = value + left;
            mini2[idx] = value - left;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid) update(2 * idx + 1, left, mid, pos, value);
        else update(2 * idx + 2, mid + 1, right, pos, value);
        mini1[idx] = min(mini1[2 * idx + 1], mini1[2 * idx + 2]);
        mini2[idx] = min(mini2[2 * idx + 1], mini2[2 * idx + 2]);
    }

public:
    SegmentTree(const vector<int>& prices) : n(prices.size()), mini1(4 * n), mini2(4 * n) {
        build(0, 0, n - 1, prices);
    }

    long long getMinPrice(int k) {
        // Query minimum price adding distance |a-b| which translates to:
        // min(prices[a] + |a - k|) = min(prices[a] + a - k, prices[a] - a + k)
        long long res1 = query1(0, 0, n - 1, 0, k);
        long long res2 = query2(0, 0, n - 1, k + 1, n - 1);
        return min(res1 - k, res2 + k);
    }

    void updatePrice(int k, int x) {
        update(0, 0, n - 1, k, x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }
    SegmentTree segTree(prices);
    for (int i = 0; i < q; ++i) {
        int type, k, x;
        cin >> type;
        if (type == 1) {
            cin >> k >> x;
            segTree.updatePrice(k - 1, x);
        } else {
            cin >> k;
            cout << segTree.getMinPrice(k - 1) << '\n';
        }
    }
    return 0;
}