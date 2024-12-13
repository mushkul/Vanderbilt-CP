#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

vector<vector<ll>> matrix_multiply(const vector<vector<ll>>& a, const vector<vector<ll>>& b) {
    vector<vector<ll>> result(6, vector<ll>(6, 0));
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 6; k++) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

vector<vector<ll>> matrix_power(vector<vector<ll>> base, ll n) {
    vector<vector<ll>> result(6, vector<ll>(6, 0));
    for (int i = 0; i < 6; i++) 
        result[i][i] = 1;
    
    while (n > 0) {
        if (n & 1) 
            result = matrix_multiply(result, base);
        base = matrix_multiply(base, base);
        n >>= 1;
    }
    return result;
}

int main() {
    ll n;
    cin >> n;
    
    vector<vector<ll>> base(6, vector<ll>(6, 0));
    for (int j = 0; j < 6; j++) 
        base[0][j] = 1;
    
    for (int i = 1; i < 6; i++) 
        base[i][i-1] = 1;
    
    if (n <= 6) {
        ll ways[7] = {1, 1, 2, 4, 8, 16, 32};
        cout << ways[n] << endl;
        return 0;
    }
    
    vector<vector<ll>> result = matrix_power(base, n - 6);
    
    ll total_ways = 0;
    for (int j = 0; j < 6; j++) 
        total_ways = (total_ways + result[0][j]) % MOD;
    
    cout << total_ways << endl;
    return 0;
}