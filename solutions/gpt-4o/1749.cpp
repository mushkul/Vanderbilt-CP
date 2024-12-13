#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; ++i) cin >> x[i];
    
    int p;
    set<int> removed_positions;
    
    for (int i = 0; i < n; ++i) {
        cin >> p;
        auto it = removed_positions.lower_bound(p);
        int idx = p + distance(removed_positions.begin(), it) - 1;
        removed_positions.insert(p);
        cout << x[idx] << " ";
    }

    return 0;
}