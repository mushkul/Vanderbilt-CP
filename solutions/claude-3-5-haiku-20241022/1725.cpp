#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<vector<double>> dp(n + 1, vector<double>(b + 1, 0.0));
    dp[0][0] = 1.0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= 6 && k <= j; k++) {
                dp[i][j] += dp[i-1][j-k] / 6.0;
            }
        }
    }
    
    double probability = 0.0;
    for (int j = a; j <= b; j++) {
        probability += dp[n][j];
    }
    
    cout << fixed << setprecision(6) << probability << endl;
    
    return 0;
}