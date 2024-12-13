#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int grundy(int n) {
    if(n <= 2) return 0;
    if(dp[n] != -1) return dp[n];
    
    set<int> s;
    for(int i = 1; i <= n/2; i++) {
        if(i != n-i) {
            s.insert(grundy(i) ^ grundy(n-i));
        }
    }
    
    int mex = 0;
    while(s.count(mex)) mex++;
    
    return dp[n] = mex;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    dp.assign(1000001, -1);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(grundy(n)) cout << "first\n";
        else cout << "second\n";
    }
    
    return 0;
}