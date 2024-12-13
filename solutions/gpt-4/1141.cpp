#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int freq[200005] = {0};
    int mx = 0, j = 0;
    for (int i=0; i<n; i++) {
        while (j < n and !freq[a[j]]) freq[a[j++]] = 1;
        mx = max(mx, j-i);
        freq[a[i]] = 0;
    }

    cout << mx;

    return 0;
}