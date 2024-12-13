#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> heaps(n);
        int xorSum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> heaps[i];
            xorSum ^= heaps[i];
        }
        
        cout << (xorSum ? "first" : "second") << endl;
    }
    
    return 0;
}