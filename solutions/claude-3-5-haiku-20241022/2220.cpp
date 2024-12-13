#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[20][10][2][2];

ll solve(string& num, int pos, int prev, bool tight, bool nonzero) {
    if (pos == num.size()) return 1;
    
    ll& ret = dp[pos][prev][tight][nonzero];
    if (ret != -1) return ret;
    
    ret = 0;
    int limit = tight ? num[pos] - '0' : 9;
    
    for (int digit = 0; digit <= limit; digit++) {
        if (nonzero && digit == prev) continue;
        
        bool newTight = tight && (digit == num[pos] - '0');
        bool newNonzero = nonzero || digit > 0;
        
        ret += solve(num, pos + 1, digit, newTight, newNonzero);
    }
    
    return ret;
}

ll countNumbers(ll a, ll b) {
    memset(dp, -1, sizeof(dp));
    string b_str = to_string(b);
    
    memset(dp, -1, sizeof(dp));
    ll b_count = solve(b_str, 0, 0, 1, 0);
    
    memset(dp, -1, sizeof(dp));
    string a_str = to_string(a - 1);
    ll a_count = solve(a_str, 0, 0, 1, 0);
    
    return b_count - a_count;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << countNumbers(a, b) << endl;
    return 0;
}