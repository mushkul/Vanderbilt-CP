#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    set<string> substrings;
    int n = s.length();
    
    for (int i = 0; i < n; i++) {
        for (int len = 1; len <= n - i; len++) {
            substrings.insert(s.substr(i, len));
        }
    }
    
    auto it = substrings.begin();
    advance(it, k - 1);
    cout << *it << endl;
    
    return 0;
}