#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[20][10][2][2];

ll solve(string& num, int pos, int prev, bool tight, bool leading_zero) {
    if(pos == num.length()) return 1;
    
    if(dp[pos][prev][tight][leading_zero] != -1)
        return dp[pos][prev][tight][leading_zero];
        
    ll result = 0;
    int upper = tight ? (num[pos] - '0') : 9;
    
    for(int digit = 0; digit <= upper; digit++) {
        if(digit == prev && !leading_zero) continue;
        bool new_tight = tight && (digit == upper);
        bool new_leading_zero = leading_zero && digit == 0;
        result += solve(num, pos + 1, digit, new_tight, new_leading_zero);
    }
    
    return dp[pos][prev][tight][leading_zero] = result;
}

ll countValid(ll n) {
    if(n < 0) return 0;
    string num = to_string(n);
    memset(dp, -1, sizeof(dp));
    return solve(num, 0, 0, 1, 1);
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << countValid(b) - countValid(a-1) << endl;
    return 0;
}