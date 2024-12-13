#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> songs(n);
    for(int i = 0; i < n; i++) {
        cin >> songs[i];
    }
    
    map<int,int> last;
    int ans = 0;
    int start = 0;
    
    for(int i = 0; i < n; i++) {
        if(last.count(songs[i]) && last[songs[i]] >= start) {
            start = last[songs[i]] + 1;
        }
        last[songs[i]] = i;
        ans = max(ans, i - start + 1);
    }
    
    cout << ans;
    
    return 0;
}