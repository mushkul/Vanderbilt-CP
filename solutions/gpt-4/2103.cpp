#include <bits/stdc++.h>
using namespace std;
vector<int> alpha[26];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) alpha[s[i]-'a'].push_back(i);
    int k; cin >> k;
    while (k--) {
        string t; cin >> t;
        int m = t.size();
        vector<int> &v = alpha[t[0]-'a'];
        int cnt = 0;
        for (int i : v) {
            if (i+m-1 >= n) continue;
            bool ok = true;
            for (int j = 1; j < m; ++j) if (s[i+j] != t[j]) { ok = false; break; }
            if (ok) ++cnt;
        }
        cout << cnt << "\n";
    }
    return 0;
}