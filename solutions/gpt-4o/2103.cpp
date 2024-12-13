#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text;
    cin >> text;
    int k;
    cin >> k;
    
    while (k--) {
        string pattern;
        cin >> pattern;
        
        string combined = pattern + '#' + text;
        vector<int> z = z_function(combined);
        
        int cnt = 0;
        for (int i = pattern.size() + 1; i < z.size(); ++i) {
            if (z[i] == pattern.size()) {
                cnt++;
            }
        }
        
        cout << cnt << '\n';
    }

    return 0;
}