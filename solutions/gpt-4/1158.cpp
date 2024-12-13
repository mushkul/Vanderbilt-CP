#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int dp[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    int h[n], s[n];
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i=0; i<n; i++){
        for(int j=x; j>=h[i]; j--){
            dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
        }
    }
    cout << dp[x];
    return 0;
}