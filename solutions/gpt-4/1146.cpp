#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countBits(ll n) {
    ll cnt = 0;
    while(n > 0) {
        n &= (n - 1);
        cnt++;
    }
    return cnt;
}

ll solve(ll n) {
    ll sum = 0;
    for(ll i = 1; i <= n; i++) {
        sum += countBits(i);
    }
    return sum;
}

int main() {
    ll n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}