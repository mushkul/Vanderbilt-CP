#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> moves(k);
    for(int i = 0; i < k; i++) {
        cin >> moves[i];
    }
    
    vector<bool> dp(n+1, false);
    
    for(int i = 1; i <= n; i++) {
        for(int move : moves) {
            if(i - move >= 0 && !dp[i-move]) {
                dp[i] = true;
                break;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << (dp[i] ? 'W' : 'L');
    }
    
    return 0;
}