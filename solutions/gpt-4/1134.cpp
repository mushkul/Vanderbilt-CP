#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> count(n+1, 1);
    set<int> available;
    vector<int> prufer(n-1);
 
    for(int i = 0; i < n-2; ++i) {
        cin >> prufer[i];
        ++count[prufer[i]];
    }
 
    for(int i = 1; i <= n; ++i) {
        if(count[i] == 1) {
            available.insert(i);
        }
    }
 
    for(int i = 0; i < n-2; i++) {
        int a = prufer[i];
        int b = *available.begin();
        --count[a];
        if(count[a] == 1) {
            available.insert(a);
        }
        available.erase(b);
        cout << a << " " << b << "\n";
    }
 
    cout << *available.begin() << " " << *available.rbegin() << "\n";
 
    return 0;
}