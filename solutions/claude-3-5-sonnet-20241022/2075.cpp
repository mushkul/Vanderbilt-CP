#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<pair<int,int>> ans;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        int mn = a[i], pos = i;
        for(int j = i+1; j < n; j++) {
            if(a[j] < mn) {
                mn = a[j];
                pos = j;
            }
        }
        
        if(pos != i) {
            ans.push_back({i+1, pos+1});
            reverse(a.begin()+i, a.begin()+pos+1);
        }
    }
    
    cout << ans.size() << "\n";
    for(auto p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
    
    return 0;
}