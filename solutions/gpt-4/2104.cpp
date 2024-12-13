#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    while(k--) {
        string pattern;
        cin >> pattern;
        size_t pos = s.find(pattern);
        if(pos != string::npos) {
            cout << pos+1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}