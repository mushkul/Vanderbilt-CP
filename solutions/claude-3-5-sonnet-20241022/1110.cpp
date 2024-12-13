#include <bits/stdc++.h>
using namespace std;

string minRotation(string s) {
    int n = s.length();
    s += s;
    int i = 0, j = 1;
    while (j < n) {
        int k = 0;
        while (k < n && s[i+k] == s[j+k]) k++;
        if (k == n) break;
        if (s[i+k] > s[j+k]) {
            i = i + k + 1;
            if (i <= j) i = j + 1;
        } else {
            j = j + k + 1;
            if (j <= i) j = i + 1;
        }
    }
    return s.substr(i, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    cout << minRotation(s) << "\n";
    return 0;
}