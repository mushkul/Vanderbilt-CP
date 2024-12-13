#include<bits/stdc++.h>
using namespace std;
bool dp[101][100001];

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    
    dp[0][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 100000; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j - x[i - 1] >= 0 && dp[i - 1][j - x[i - 1]]) dp[i][j] = true;
        }
    }
    
    vector<int> sums;
    for (int j = 1; j <= 100000; ++j) {
        if (dp[n][j]) sums.push_back(j);
    }

    cout<<sums.size()<<endl;
    for (int s : sums) {
        cout<<s<<' ';
    }

    return 0;
}