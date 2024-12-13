#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;

int dp[1<<11][1005], n, m;

int f(int mask, int it){
    if(it==m) return mask==0;
    if(dp[mask][it] != -1) return dp[mask][it];
    int &ret=dp[mask][it];
    ret=0;
    for(int i=0; i<(1<<n); i++){
        bool can=true;
        for(int j=0; j<n; j++){
            if((mask>>j&1) == (i>>j&1)){
                if(j and ((i>>j&1)==(i>>(j-1)&1))) can=false;
            }else{
                if(j and (i>>j&1) and (i>>(j-1)&1)) can=false;
                if((i>>j&1) == 0 and j and ((mask>>(j-1)&1)==0))can=false;
                if(j<n-1 and ((i>>j&1) == 0) and ((mask>>(j+1)&1)==0)) can=false;
            }
        }
        if(can) ret=(ret+f(i, it+1))%mod;
    }
    return ret;
}

int main(){
    cin>>n>>m;
    memset(dp, -1, sizeof dp);
    cout<<f(0, 0)<<endl;
    return 0;
}