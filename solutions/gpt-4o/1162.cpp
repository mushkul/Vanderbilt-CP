#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> perm(n), sorted_perm(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> perm[i];
        sorted_perm[i] = perm[i];
    }
    
    sort(sorted_perm.begin(), sorted_perm.end());
    
    int adjacent_swaps = 0, any_swaps = 0, move_to_position = 0, move_to_front = 0;
    
    // Calculate adjacent_swaps using Bubble Sort count heuristic
    vector<int> a = perm;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                adjacent_swaps++;
            }
        }
    }
    
    // Calculate any_swaps using inversion count
    unordered_map<int, int> index_map;
    for (int i = 0; i < n; i++) {
        index_map[sorted_perm[i]] = i;
    }
    vector<int> indexes(n);
    for (int i = 0; i < n; i++) {
        indexes[i] = index_map[perm[i]];
    }
    vector<int> bit(n + 1, 0);
    auto add = [&](int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    };
    auto get_sum = [&](int idx) -> int {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    };
    for (int i = n - 1; i >= 0; i--) {
        any_swaps += get_sum(indexes[i]);
        add(indexes[i], 1);
    }
    
    // Calculate move_to_position using LIS in the index array
    vector<int> lis(n + 1, INT_MAX);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(lis.begin(), lis.end(), indexes[i]) - lis.begin();
        lis[pos] = indexes[i];
    }
    move_to_position = n - (lower_bound(lis.begin(), lis.end(), INT_MAX) - lis.begin());
    
    // Calculate move_to_front as n minus LIS length in indexes
    move_to_front = move_to_position;
    
    cout << adjacent_swaps << " " << any_swaps << " " << move_to_position << " " << move_to_front << endl;
    
    return 0;
}