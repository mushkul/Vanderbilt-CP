#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> array(n + 1), change_pos(m), change_val(m);
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> change_pos[i] >> change_val[i];
    }
    
    // Segment tree data structures
    vector<int> tree_max(4 * n, 0), tree_sum(4 * n, 0), tree_best_prefix(4 * n, 0), tree_best_suffix(4 * n, 0);
    
    // Build the initial segment tree
    function<void(int, int, int)> build = [&](int node, int start, int end) {
        if (start == end) {
            int val = array[start];
            tree_max[node] = max(0, val);
            tree_sum[node] = val;
            tree_best_prefix[node] = max(0, val);
            tree_best_suffix[node] = max(0, val);
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
            tree_best_prefix[node] = max(tree_best_prefix[2 * node], tree_sum[2 * node] + tree_best_prefix[2 * node + 1]);
            tree_best_suffix[node] = max(tree_best_suffix[2 * node + 1], tree_sum[2 * node + 1] + tree_best_suffix[2 * node]);
            tree_max[node] = max({tree_max[2 * node], tree_max[2 * node + 1], tree_best_suffix[2 * node] + tree_best_prefix[2 * node + 1]});
        }
    };
    
    // Update the segment tree
    function<void(int, int, int, int, int)> update = [&](int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree_max[node] = max(0, value);
            tree_sum[node] = value;
            tree_best_prefix[node] = max(0, value);
            tree_best_suffix[node] = max(0, value);
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node, start, mid, idx, value);
            } else {
                update(2 * node + 1, mid + 1, end, idx, value);
            }
            tree_sum[node] = tree_sum[2 * node] + tree_sum[2 * node + 1];
            tree_best_prefix[node] = max(tree_best_prefix[2 * node], tree_sum[2 * node] + tree_best_prefix[2 * node + 1]);
            tree_best_suffix[node] = max(tree_best_suffix[2 * node + 1], tree_sum[2 * node + 1] + tree_best_suffix[2 * node]);
            tree_max[node] = max({tree_max[2 * node], tree_max[2 * node + 1], tree_best_suffix[2 * node] + tree_best_prefix[2 * node + 1]});
        }
    };

    build(1, 1, n);

    for (int i = 0; i < m; i++) {
        int pos = change_pos[i];
        int val = change_val[i];
        update(1, 1, n, pos, val);
        cout << tree_max[1] << endl;
    }

    return 0;
}