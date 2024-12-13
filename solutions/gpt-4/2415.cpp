#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

int fac[5005];
int inv_fac[5005];
int n;
int dp[5005][5005];
int poww[5005][5005];

int multi(int a, int b){
    return ((long long) a * b) % mod;
}

int add(int a, int b){
    return (a + b) % mod;
}

int power(int a, int b){
    int ans = 1;
    while(b){
        if(b & 1){
            ans = multi(ans, a);
        }
        a = multi(a, a);
        b /= 2;
    }
    return ans;
}

int C(int n, int m){
    return multi(fac[n], multi(inv_fac[m], inv_fac[n - m]));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fac[0] = inv_fac[0] = 1;
    for(int i = 1; i <= 5000; i++){
        fac[i] = multi(fac[i - 1], i);
        inv_fac[i] = power(fac[i], mod - 2);
        poww[i][1] = i;
        for(int j = 2; j <= 5000; j++){
            poww[i][j] = multi(poww[i][j - 1], i);
        }
    }

    cin >> n;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = add(dp[i][j], dp[i - j][j - 1]);
            dp[i][j] = add(dp[i][j], multi(dp[i - 1][j - 1], j));
        }
    }

    for(int i = 1; i <= n; i++){
        int ans = 0;
        for(int j = i; j <= n; j++){
            ans = add(ans, multi(C(n, j), multi(poww[j][i], dp[j][i])));
        }
        cout << ans << '\n';
    }
    
    return 0;
}