#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) 
        cin >> v[i];
    
    vector<vector<int>> dp(n+1,vector<int>(19));
    for(int i = 1; i <= n; i++)
        dp[i][0] = v[i];

    for(int j = 1; j <= 18; j++)
        for(int i = 1; i <= n; i++)
        {
            dp[i][j] = dp[i][j-1];
            int idx = i+(1<<(j-1));
            if(idx <= n)
                dp[i][j] = min(dp[i][j],dp[idx][j-1]);
        }
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        int k = log2(b-a+1);
        cout << min(dp[a][k],dp[b-(1<<k)+1][k]) << "\n";
    }
    return 0;
}