#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> ans(n);
    stack<pair<int,int>> s1, s2;
    int next = 1;
    int pos = 0;
    
    while (pos < n || !s1.empty() || !s2.empty()) {
        bool moved = false;
        
        if(!s1.empty() && s1.top().first == next) {
            ans[s1.top().second] = 1;
            next++;
            s1.pop();
            moved = true;
        }
        
        if(!s2.empty() && s2.top().first == next) {
            ans[s2.top().second] = 2;
            next++;
            s2.pop();
            moved = true;
        }
        
        if(pos < n) {
            if(s1.empty() || a[pos] < s1.top().first) {
                s1.push({a[pos], pos});
                pos++;
                moved = true;
            }
            else if(s2.empty() || a[pos] < s2.top().first) {
                s2.push({a[pos], pos});
                pos++;
                moved = true;
            }
        }
        
        if(!moved) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
}