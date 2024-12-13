#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 5;

long long factorial[MAX_N];
long long invFactorial[MAX_N];

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

void precompute() {
    factorial[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
    invFactorial[MAX_N-1] = modInverse(factorial[MAX_N-1]);
    for (int i = MAX_N-2; i >= 0; i--) {
        invFactorial[i] = (invFactorial[i+1] * (i+1)) % MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    string s;
    cin >> s;
    
    int freq[26] = {0};
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    long long ans = factorial[s.length()];
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {
            ans = (ans * invFactorial[freq[i]]) % MOD;
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}