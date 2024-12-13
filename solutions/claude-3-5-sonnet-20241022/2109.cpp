#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<pair<string, int>> generateSubstrings(string& s) {
    int n = s.length();
    vector<pair<string, int>> subs;
    for(int i = 0; i < n; i++) {
        for(int j = 1; i + j <= n; j++) {
            subs.push_back({s.substr(i, j), i});
        }
    }
    return subs;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    ll k;
    cin >> s >> k;
    
    vector<pair<string, int>> substrings = generateSubstrings(s);
    sort(substrings.begin(), substrings.end());
    
    cout << substrings[k-1].first << "\n";
    
    return 0;
}