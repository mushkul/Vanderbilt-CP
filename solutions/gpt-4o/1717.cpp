#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n + 1);
    dp[0] = 1;
    if (n > 0) dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n] << endl;
    return 0;
}