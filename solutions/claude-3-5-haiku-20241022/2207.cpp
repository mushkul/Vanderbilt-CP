#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    vector<int> grundy(1000001, 0);
    
    for (int i = 1; i <= 1000000; i++) {
        vector<bool> s(i + 1, false);
        
        for (int j = 1; j < i; j++) {
            if (j != i - j) {
                s[grundy[j] ^ grundy[i - j]] = true;
            }
        }
        
        for (int j = 0; j <= i; j++) {
            if (!s[j]) {
                grundy[i] = j;
                break;
            }
        }
    }
    
    while (t--) {
        int n;
        cin >> n;
        
        cout << (grundy[n] ? "first" : "second") << endl;
    }
    
    return 0;
}