#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        
        long long xorSum = 0;
        for (int i = 1; i < n; i++) {
            xorSum ^= p[i];
        }
        
        cout << (xorSum ? "first" : "second") << endl;
    }
    
    return 0;
}