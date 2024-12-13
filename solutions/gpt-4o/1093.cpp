#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    int totalSum = n * (n + 1) / 2;
    if (totalSum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int target = totalSum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    
    for (int num = 1; num <= n; ++num) {
        for (int sum = target; sum >= num; --sum) {
            dp[sum] = (dp[sum] + dp[sum - num]) % MOD;
        }
    }
    
    cout << (dp[target] * 500000004LL) % MOD << endl; //The multiplicative inverse of 2 under modulo 1e9+7
    return 0;
}