#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<int> distinctValues;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        distinctValues.insert(x);
    }
    
    cout << distinctValues.size() << endl;
    
    return 0;
}