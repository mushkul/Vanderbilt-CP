#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    s = " " + s;
    int n = s.size();
    vector<vector<int>> nxt(n, vector<int>(4, n));
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < 4; ++j)
            nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i + 1] - 'A'] = i + 1;
    }
    
    string ans;
    int i = 0;
    while (i < n) {
        int mx = 0;
        for (int j = 1; j < 4; ++j) 
            if (nxt[i][j] > nxt[i][mx]) 
                mx = j;

        ans += 'A' + mx;
        i = nxt[i][mx];
    }
    cout << ans;
    return 0;
}