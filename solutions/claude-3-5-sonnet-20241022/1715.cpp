#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

ll power(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

ll modInv(ll n) {
    return power(n, MOD-2);
}

int main() {
    string s;
    cin >> s;
    vector<ll> fact(1000001);
    fact[0] = 1;
    for(int i = 1; i <= 1000000; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    
    vector<int> count(26, 0);
    for(char c : s) {
        count[c - 'a']++;
    }
    
    ll answer = fact[s.length()];
    for(int i = 0; i < 26; i++) {
        if(count[i] > 1) {
            answer = (answer * modInv(fact[count[i]])) % MOD;
        }
    }
    
    cout << answer << endl;
    return 0;
}