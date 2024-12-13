#include<bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int main(){
    string a, b;
    cin>>a;
    cin>>b;
    for(int i = 1; i <= a.size(); i++) dp[i][0] = i;
    for(int i = 1; i <= b.size(); i++) dp[0][i] = i;

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
    }
    cout<<dp[a.size()][b.size()]<<endl;
    return 0;
}