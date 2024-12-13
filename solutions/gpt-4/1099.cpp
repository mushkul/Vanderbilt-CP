#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int& x : p) cin >> x;
        int i = 0;
        while (i < n && p[i] == 1) ++i;
        if (i == n || i % 2 == 1) cout << "second\n";
        else cout << "first\n";
    }

    return 0;
}