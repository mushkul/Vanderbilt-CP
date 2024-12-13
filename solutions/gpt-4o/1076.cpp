#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    multiset<int> low, high;
    auto add = [&](int val) {
        if (low.empty() || val <= *low.rbegin()) {
            low.insert(val);
        } else {
            high.insert(val);
        }
        if (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(--low.end());
        } else if (high.size() > low.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    };
    
    auto remove = [&](int val) {
        if (low.find(val) != low.end()) {
            low.erase(low.find(val));
        } else {
            high.erase(high.find(val));
        }
    };

    for (int i = 0; i < k; ++i) {
        add(x[i]);
    }

    cout << *low.rbegin();
    
    for (int i = k; i < n; ++i) {
        add(x[i]);
        remove(x[i - k]);
        cout << " " << *low.rbegin();
    }
    
    return 0;
}