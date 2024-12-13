#include <bits/stdc++.h>
using namespace std;
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

string text, pattern;
vector<int> prefix_func(string s) {
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
    fastIO()
    cin >> text >> pattern;
    string concatn = pattern + "#" + text;
    vector<int> lps = prefix_func(concatn);
    int cnt = 0;
    for(int i=pattern.size();i<concatn.size();i++)
        if(lps[i] == pattern.size())
            cnt++;
    cout <<cnt;
    return 0;
}