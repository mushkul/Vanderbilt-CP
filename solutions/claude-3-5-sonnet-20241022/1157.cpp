#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll solve(ll y, ll x) {
    return max(y - 1, x - 1);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll y, x;
    cin >> y >> x;
    cout << solve(y, x) << '\n';
    
    return 0;
}