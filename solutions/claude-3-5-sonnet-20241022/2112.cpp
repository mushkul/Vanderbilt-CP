#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    for (int k = 1; k < n; k++) {
        int count = 0;
        for (int i = 0; i + k < n; i++) {
            if (s[i] == '1' && s[i + k] == '1') {
                count++;
            }
        }
        cout << count;
        if (k < n - 1) cout << " ";
    }
    
    return 0;
}