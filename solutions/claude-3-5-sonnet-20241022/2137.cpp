#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<bitset<3000>> grid(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < n; j++) {
            if(s[j] == '1') grid[i][j] = 1;
        }
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            ll count = (grid[i] & grid[j]).count();
            ans += (count * (count-1))/2;
        }
    }
    
    cout << ans << '\n';
    return 0;
}