#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), lis_inc(n), lis_dec(n);
    for (int &x : a) cin >> x;

    vector<int> seq;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(seq.begin(), seq.end(), a[i]);
        if (it == seq.end()) seq.push_back(a[i]);
        else *it = a[i];
        lis_inc[i] = seq.size();
    }

    seq.clear();
    for (int i = n - 1; i >= 0; --i) {
        auto it = lower_bound(seq.begin(), seq.end(), a[i]);
        if (it == seq.end()) seq.push_back(a[i]);
        else *it = a[i];
        lis_dec[i] = seq.size();
    }

    int max_length = 0;
    for (int i = 0; i < n; ++i) {
        max_length = max(max_length, lis_inc[i] + lis_dec[i] - 1);
    }

    cout << n - max_length << endl;
    return 0;
}