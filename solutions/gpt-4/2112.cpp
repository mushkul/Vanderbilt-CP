#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    vector<int> prefix(s.size(), 0), res(s.size(), 0);
    prefix[0] = s[0] - '0';
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '1') {
            res[i] += prefix[i - 1];
        }
        prefix[i] = prefix[i - 1] + (s[i] == '1');
    }
    vector<int> ans(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        if (res[i] > 0) {
            ans[res[i]]++;
        }
    }
    for (int i = s.size(); i > 0; i--) {
        ans[i - 1] += ans[i];
    }
    for (int i = 1; i < s.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}