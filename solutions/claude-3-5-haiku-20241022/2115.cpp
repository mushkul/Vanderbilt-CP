#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<int> count(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        int ones = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '1') {
                ones++;
            }
            count[ones]++;
        }
    }
    
    for (int k = 0; k <= n; k++) {
        cout << count[k] << " ";
    }
    
    return 0;
}