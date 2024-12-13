#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    
    set<int> lights{0, x};
    multiset<int> lengths{x};
    
    for(int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        
        auto it = lights.upper_bound(pos);
        auto prev_it = prev(it);
        
        lengths.erase(lengths.find(*it - *prev_it));
        lengths.insert(pos - *prev_it);
        lengths.insert(*it - pos);
        lights.insert(pos);
        
        cout << *lengths.rbegin() << " ";
    }
    
    return 0;
}