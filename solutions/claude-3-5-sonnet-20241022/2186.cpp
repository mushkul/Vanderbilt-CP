#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.length();
    ll ans = 0;
    
    for(int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        for(int j = i; j < n; j++) {
            freq[s[j] - 'a']++;
            bool special = true;
            int nonZero = 0;
            for(int k = 0; k < 26; k++) {
                if(freq[k] > 0) {
                    if(nonZero == 0) nonZero = freq[k];
                    else if(freq[k] != nonZero) {
                        special = false;
                        break;
                    }
                }
            }
            if(special) ans++;
        }
    }
    
    cout << ans << "\n";
    return 0;
}