#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<double> dp(k + 1, 0.0);
    
    for (int candies = 1; candies <= k; ++candies) {
        dp[candies] = pow(candies / (double)k, n);
    }
    
    double expectedMax = 0.0;
    for (int candies = 1; candies <= k; ++candies) {
        expectedMax += candies * (dp[candies] - dp[candies - 1]);
    }
    
    cout << fixed << setprecision(6) << expectedMax << endl;
    
    return 0;
}