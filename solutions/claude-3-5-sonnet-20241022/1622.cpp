#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
string s;

void permute(string curr, int used[], int n) {
    if (curr.size() == n) {
        ans.push_back(curr);
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (!used[i] && (i == 0 || s[i] != s[i-1] || used[i-1])) {
            used[i] = 1;
            permute(curr + s[i], used, n);
            used[i] = 0;
        }
    }
}

int main() {
    cin >> s;
    sort(s.begin(), s.end());
    
    int n = s.length();
    int used[8] = {0};
    
    permute("", used, n);
    
    cout << ans.size() << "\n";
    for (string str : ans) {
        cout << str << "\n";
    }
    
    return 0;
}