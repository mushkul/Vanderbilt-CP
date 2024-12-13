#include <bits/stdc++.h>
using namespace std;

vector<int> findBorders(string s) {
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
    
    vector<int> borders;
    int len = pi[n-1];
    while (len > 0) {
        borders.push_back(len);
        len = pi[len-1];
    }
    
    sort(borders.begin(), borders.end());
    return borders;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    vector<int> result = findBorders(s);
    for (int x : result) {
        cout << x << " ";
    }
    
    return 0;
}