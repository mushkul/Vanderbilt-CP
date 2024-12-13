#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if(i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    int n = s.length();
    string ans = "-1";
    int maxLen = 0;
    
    for(int i = 0; i < n; i++) {
        vector<int> z = z_function(s.substr(i));
        for(int j = 1; j < z.size(); j++) {
            if(z[j] >= maxLen && z[j] <= n-i-j) {
                maxLen = z[j];
                ans = s.substr(i, maxLen);
            }
        }
    }
    
    if(maxLen > 0)
        cout << ans << "\n";
    else
        cout << "-1\n";
        
    return 0;
}