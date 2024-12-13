#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    string longestRepeating = "-1";
    
    for (int len = n/2; len > 0; len--) {
        for (int i = 0; i <= n - 2*len; i++) {
            string substring = s.substr(i, len);
            for (int j = i + len; j <= n - len; j++) {
                if (s.substr(j, len) == substring) {
                    longestRepeating = substring;
                    break;
                }
            }
            if (longestRepeating != "-1") break;
        }
        if (longestRepeating != "-1") break;
    }
    
    cout << longestRepeating << endl;
    return 0;
}