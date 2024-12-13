#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int find_pattern(string text, string pattern) {
    string combined = pattern + "#" + text;
    vector<int> pi = prefix_function(combined);
    int n = combined.length();
    int p_len = pattern.length();
    
    for(int i = p_len + 1; i < n; i++) {
        if(pi[i] == p_len) {
            return i - 2*p_len + 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string text;
    cin >> text;
    
    int k;
    cin >> k;
    
    for(int i = 0; i < k; i++) {
        string pattern;
        cin >> pattern;
        int pos = find_pattern(text, pattern);
        cout << (pos == -1 ? -1 : pos + 1) << "\n";
    }
    
    return 0;
}