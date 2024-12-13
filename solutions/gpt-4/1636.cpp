#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
 
int main(){
    int n,x; cin>>n>>x;
    int coins[n];
    for(int i=0; i<n; i++) cin>>coins[i];
 
    vector<long long> dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=x;j++){
            if(j>=coins[i]){
                dp[j]=(dp[j]+dp[j-coins[i]])%MOD;
            }
        }
    }
    cout << dp[x] << endl;
    return 0;
}