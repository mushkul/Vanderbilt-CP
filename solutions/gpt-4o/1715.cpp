#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

typedef long long ll;

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b % 2) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

ll modInverse(ll a, ll mod) {
    return power(a, mod - 2, mod);
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    vector<ll> fact(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    ll result = fact[n];
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {
            result = (result * modInverse(fact[freq[i]], MOD)) % MOD;
        }
    }
    cout << result << endl;
    return 0;
}