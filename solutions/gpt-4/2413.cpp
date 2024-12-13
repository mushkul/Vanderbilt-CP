C++
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
const ll MOD = 1e9 + 7;
const int MAX = 1e6 + 5;
ll dp[MAX][2];

void pre() {
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i < MAX; ++i) {
        dp[i][0] = (3*dp[i-1][0] + dp[i-1][1]) % MOD;
        dp[i][1] = (2*dp[i-1][0] + 2*dp[i-1][1]) % MOD;
    }
}

int main () {
	int t;
	cin >> t;

    pre();
	while(t--) {
	    int n;
	    cin >> n;
	    cout << (dp[n][0] + dp[n][1]) % MOD << endl;
	}
	
	return 0;
}