#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            int pos = s.find('A', i + 1);
            if (pos == string::npos) {
                cout << "-1\n";
                return 0;
            }
            while (pos > i) {
                swap(s[pos], s[pos - 1]);
                ans.push_back({pos, pos - 1});
                pos--;
            }
        }
    }
    cout << ans.size() << "\n";
    for (auto &p : ans) {
        cout << p.second + 1 << " " << p.first + 1 << "\n";
    }
    return 0;
}