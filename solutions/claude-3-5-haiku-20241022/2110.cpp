#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<int> result(n);
    for (int len = 1; len <= n; len++) {
        unordered_set<string> distinct;
        for (int i = 0; i + len <= n; i++) {
            distinct.insert(s.substr(i, len));
        }
        result[len-1] = distinct.size();
    }
    
    for (int x : result) {
        cout << x << " ";
    }
    
    return 0;
}