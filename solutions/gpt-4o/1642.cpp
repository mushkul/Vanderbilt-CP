#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    unordered_map<int, pair<int, int>> two_sum_map;
    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int remaining = x - a[i] - a[j];
            if (two_sum_map.count(remaining)) {
                auto p = two_sum_map[remaining];
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    cout << p.first + 1 << " " << p.second + 1 << " " << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
        for (int j = 0; j < i; ++j) {
            two_sum_map[a[i] + a[j]] = {j, i};
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}