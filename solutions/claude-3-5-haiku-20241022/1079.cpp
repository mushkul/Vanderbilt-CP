#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 1;

long long fact[MAX_N];
long long invfact[MAX_N];

long long power(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }
    invfact[MAX_N-1] = power(fact[MAX_N-1], MOD-2);
    for (int i = MAX_N-2; i >= 0; i--) {
        invfact[i] = (invfact[i+1] * (i+1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (r > n) return 0;
    return (((fact[n] * invfact[r]) % MOD) * invfact[n-r]) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precompute();
    
    int n;
    cin >> n;
    
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << nCr(a, b) << '\n';
    }
    
    return 0;
}