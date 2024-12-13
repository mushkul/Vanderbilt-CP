#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7;
 
int main() {
    string s;
    cin >> s;
    
    set<string> unique_strings;
    int n = s.length();
    
    for (int mask = 0; mask < (1 << n); mask++) {
        string curr = "";
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                curr += s[j];
            }
        }
        unique_strings.insert(curr);
    }
    
    cout << unique_strings.size() << endl;
    return 0;
}