#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll digitCount(ll n) {
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7; 
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    if (n < 10000000000) return 10;
    if (n < 100000000000) return 11;
    if (n < 1000000000000) return 12;
    if (n < 10000000000000) return 13;
    if (n < 100000000000000) return 14;
    if (n < 1000000000000000) return 15;
    if (n < 10000000000000000) return 16;
    if (n < 100000000000000000) return 17;
    return 18;
}

ll solve(ll k) {
    ll len = 1;
    ll cnt = 9;
    ll start = 1;
    
    while (k > len * cnt) {
        k -= len * cnt;
        len++;
        cnt *= 10;
        start *= 10;
    }
    
    start += (k-1)/len;
    string num = to_string(start);
    return num[(k-1)%len] - '0';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        cout << solve(k) << "\n";
    }
    return 0;
}