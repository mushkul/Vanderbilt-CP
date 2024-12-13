#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            sum += x - 1;
        }
        
        if (sum % 2 == 0) {
            cout << "second\n";
        } else {
            cout << "first\n";
        }
    }
    
    return 0;
}