#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> result;
    
    for(int len = 1; len <= n; len++) {
        bool valid = true;
        for(int i = 0; i < n; i++) {
            if(i < n && s[i] != s[i % len]) {
                valid = false;
                break;
            }
        }
        if(valid) {
            result.push_back(len);
        }
    }
    
    for(int i = 0; i < result.size(); i++) {
        if(i > 0) cout << " ";
        cout << result[i];
    }
    cout << endl;
    
    return 0;
}