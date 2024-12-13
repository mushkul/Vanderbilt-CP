#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        unordered_set<int> distinct;
        for (int i = a; i <= b; i++) {
            distinct.insert(arr[i]);
        }
        
        cout << distinct.size() << "\n";
    }
    
    return 0;
}