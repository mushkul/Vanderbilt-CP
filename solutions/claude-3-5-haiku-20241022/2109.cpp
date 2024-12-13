#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string solve(string s, ll k) {
    int n = s.length();
    vector<pair<string, int>> substrings;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            substrings.push_back({s.substr(i, j-i+1), i});
        }
    }
    
    sort(substrings.begin(), substrings.end());
    
    return substrings[k-1].first;
}

int main() {
    string s;
    ll k;
    cin >> s >> k;
    cout << solve(s, k) << endl;
    return 0;
}