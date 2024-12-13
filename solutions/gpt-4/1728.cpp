#include<bits/stdc++.h>
using namespace std;

const int maxn = 105;
double dp[maxn][maxn*maxn], p[maxn][maxn*maxn];
int r[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin >> n;

    for(int i=1;i<=n;++i) cin >> r[i];

    for(int i=1;i<maxn*maxn;++i) p[1][i] = 1.0/i;
    for(int i=2;i<maxn;++i)
        for(int j=i;j<maxn*maxn;++j)
            p[i][j] = p[i][j-1] + 1.0/j;

    for(int i=n;i;--i) {
        for(int j=1;j<=r[i];++j) {
            for(int k=1;k<j;++k)
                dp[i][j] += dp[i+1][k] + p[i+1][k];
            dp[i][j] /= r[i];
        }
        for(int j=r[i]+1;j<maxn*maxn;++j)
            dp[i][r[i]] += dp[i+1][j] + p[i+1][j];
        for(int j=r[i]-1;j;--j)
            dp[i][j] += dp[i][j+1];
    }

    printf("%.6lf\n", dp[1][1]);

    return 0;
}