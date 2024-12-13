#include <bits/stdc++.h>
using namespace std;

string s;
set<int> pos;
multiset<int> lengths;

void update(int index) {
    auto it = pos.find(index);
    int left = (it == pos.begin()) ? 0 : *prev(it);
    auto nxt = next(it);
    int right = (nxt == pos.end()) ? s.length() : *nxt;
    
    lengths.erase(lengths.find(index - left));
    lengths.erase(lengths.find(right - index));
    
    lengths.insert(index - left);
    lengths.insert(right - index);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    int m;
    cin >> m;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            pos.insert(i);
        }
    }
    
    for (int i = 0; i < s.length(); i++) {
        if (i == 0 || s[i] != s[i-1]) {
            int j = i;
            while (j < s.length() && s[j] == s[i]) j++;
            lengths.insert(j - i);
        }
    }
    
    while (m--) {
        int x;
        cin >> x;
        x--;
        
        s[x] = (s[x] == '0') ? '1' : '0';
        
        if (s[x] == '1') pos.insert(x);
        else pos.erase(x);
        
        update(x);
        if (x > 0) update(x-1);
        if (x < s.length() - 1) update(x+1);
        
        cout << *lengths.rbegin() << "\n";
    }
    
    return 0;
}