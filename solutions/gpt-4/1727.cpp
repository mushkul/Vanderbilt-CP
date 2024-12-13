#include <bits/stdc++.h>
using namespace std;

double dp[105]={0.0}, p[105]={0.0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k; 
    cin >> n >> k;
    for (int i = 1; i <= k; i++){
        p[i] = pow(i * 1.0 / k, n) - pow((i - 1) * 1.0 / k, n);
        dp[i] = dp[i - 1] + p[i] * i;
    }
    cout<<fixed<<setprecision(6)<<dp[k]<<'\n';

    return 0;
}