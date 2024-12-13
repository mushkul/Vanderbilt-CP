#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.length();
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

bool kmp(string text, string pattern) {
    string combined = pattern + "#" + text;
    vector<int> pi = prefix_function(combined);
    int n = pattern.length();
    
    for(int i = n + 1; i < combined.length(); i++) {
        if(pi[i] == n) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string text;
    cin >> text;
    
    int k;
    cin >> k;
    
    while(k--) {
        string pattern;
        cin >> pattern;
        if(kmp(text, pattern))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
    return 0;
}