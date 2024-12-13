#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFunction(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string text, pattern;
    cin >> text >> pattern;
    
    string combined = pattern + '#' + text;
    vector<int> pi = prefixFunction(combined);
    
    int count = 0;
    int patternLen = pattern.length();
    
    for(int i = patternLen + 1; i < combined.length(); i++) {
        if(pi[i] == patternLen) {
            count++;
        }
    }
    
    cout << count << "\n";
    return 0;
}