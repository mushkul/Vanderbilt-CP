#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(){
    int n;
    cin>>n;

    vector<vector<int>> dp(n, vector<int>(n,0));
    vector<string> grid(n);

    for(int i = 0; i < n; i++)
        cin >> grid[i];


    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout << 0;
        return 0;
    }


    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == '.'){
                if(i > 0)
                    dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
                if(j > 0)
                    dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
            }
        }
    }

    cout << dp[n-1][n-1];

    return 0;
}