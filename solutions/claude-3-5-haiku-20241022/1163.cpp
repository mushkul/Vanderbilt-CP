#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;
    
    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    
    multiset<int> gaps;
    gaps.insert(x);
    
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        
        auto it = lights.upper_bound(p);
        auto prev_it = prev(it);
        
        int gap = *it - *prev_it;
        gaps.erase(gaps.find(gap));
        
        gaps.insert(p - *prev_it);
        gaps.insert(*it - p);
        
        lights.insert(p);
        
        cout << *gaps.rbegin() << " ";
    }
    
    return 0;
}