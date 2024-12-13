#include<bits/stdc++.h>
using namespace std;
int hamming(string x, string y, int k) {
    int d = 0;
    for (int i = 0; i < k; i++) {
        if (x[i] != y[i]) {
            d++;
        }
    }
    return d;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (auto &x : s) {
        cin >> x;
    }
    int res = 1e9+7;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            res = min(res, hamming(s[i], s[j], k));
        }
    }
    cout << res << "\n";
    return 0;
}