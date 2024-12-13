#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinctSubstrings(string s) {
    int n = s.length();
    vector<int> result(n);
    
    for(int len = 1; len <= n; len++) {
        set<string> distinct;
        for(int i = 0; i <= n-len; i++) {
            distinct.insert(s.substr(i, len));
        }
        result[len-1] = distinct.size();
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    
    vector<int> result = countDistinctSubstrings(s);
    for(int x : result) {
        cout << x << " ";
    }
    
    return 0;
}