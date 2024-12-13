#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for(int L=n-1; L>=0; L--)
        for(int R=L; R<n; R++)
        {
            if(L==R)
                dp[L][R] = a[L];
            else
                dp[L][R] = max(a[L]-dp[L+1][R], a[R]-dp[L][R-1]);
        }
    cout << (accumulate(a.begin(), a.end(), 0LL) + dp[0][n-1]) / 2;
    return 0;
}