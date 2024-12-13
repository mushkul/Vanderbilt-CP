#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    multiset<int> towers;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = towers.upper_bound(x);
        if(it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(x);
    }
    
    cout << towers.size() << "\n";
    
    return 0;
}