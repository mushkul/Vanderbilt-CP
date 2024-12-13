#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    
    vector<pair<int, char>> freq(26);
    for(int i = 0; i < 26; i++) {
        freq[i].second = 'A' + i;
    }
    
    for(char c : s) {
        freq[c - 'A'].first++;
    }
    
    sort(freq.begin(), freq.end());
    
    string ans;
    vector<char> remaining;
    
    for(int i = 25; i >= 0; i--) {
        if(freq[i].first == 0) continue;
        
        int count = freq[i].first;
        char c = freq[i].second;
        
        if(count > (s.length() + 1) / 2) {
            cout << -1;
            return 0;
        }
        
        for(int j = 0; j < count; j++) {
            remaining.push_back(c);
        }
    }
    
    ans = string(s.length(), '.');
    int j = 0;
    
    for(int i = 0; i < s.length(); i += 2) {
        ans[i] = remaining[j++];
    }
    
    for(int i = 1; i < s.length(); i += 2) {
        ans[i] = remaining[j++];
    }
    
    for(int i = 1; i < s.length(); i++) {
        if(ans[i] == ans[i-1]) {
            cout << -1;
            return 0;
        }
    }
    
    cout << ans;
    return 0;
}