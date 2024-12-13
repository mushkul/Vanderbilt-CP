#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> ans(n + 1, 0);
    
    for(int i = 0; i < n; i++) {
        vector<int> ones;
        int count = 0;
        for(int j = i; j < n; j++) {
            if(s[j] == '1') count++;
            ans[count]++;
        }
    }
    
    for(int i = 0; i <= n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}