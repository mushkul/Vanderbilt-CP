#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int xorSum = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            xorSum ^= x;
        }
        
        cout << (xorSum ? "first" : "second") << endl;
    }
    
    return 0;
}