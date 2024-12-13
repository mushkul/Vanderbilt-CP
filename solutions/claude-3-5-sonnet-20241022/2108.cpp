#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    long long k;
    cin >> k;
    
    set<string> substrings;
    
    for(int i = 0; i < s.length(); i++) {
        string temp = "";
        for(int j = i; j < s.length(); j++) {
            temp += s[j];
            substrings.insert(temp);
        }
    }
    
    auto it = substrings.begin();
    advance(it, k-1);
    cout << *it << "\n";
    
    return 0;
}