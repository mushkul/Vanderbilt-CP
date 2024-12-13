#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

ll dp[501][125251], n, total;

ll solve(int i, int sum) {
    if(i > n) return sum == total / 2;
    if(dp[i][sum] != -1) return dp[i][sum];
    return dp[i][sum] = (solve(i + 1, sum) + solve(i + 1, sum + i)) % mod;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    total = n * (n + 1) / 2;
    if(total % 2 != 0) {
        cout << 0;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << (solve(1, 0) * pow(2, mod - 2)) % mod;
    return 0;
}