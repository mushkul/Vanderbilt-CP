#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
int n,k;
string s,t;

int countPattern(string& str, string& pat) {
    int count = 0;
    int m = pat.length();
    int n = str.length();
    
    for(int i = 0; i <= n-m; i++) {
        bool match = true;
        for(int j = 0; j < m; j++) {
            if(str[i+j] != pat[j]) {
                match = false;
                break;
            }
        }
        if(match) count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    cin >> k;
    
    while(k--) {
        cin >> t;
        cout << countPattern(s,t) << "\n";
    }
    
    return 0;
}