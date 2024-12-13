#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; i++) {
        if (i > r) {
            l = r = i;
            while (r < n && s[r-l] == s[r]) r++;
            z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if (z[k] < r - i + 1) {
                z[i] = z[k];
            } else {
                l = i;
                while (r < n && s[r-l] == s[r]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

vector<int> kmp_prefix(string s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;
    
    vector<int> z = z_function(s);
    vector<int> pi = kmp_prefix(s);
    
    z[0] = 0;
    
    for (int x : z) cout << x << " ";
    cout << endl;
    for (int x : pi) cout << x << " ";
    
    return 0;
}