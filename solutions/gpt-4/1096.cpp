#include<bits/stdc++.h>
#define mod 1000000007
#define int long long

using namespace std;

int matpow[100][10][10];

int v[7] = {0,1,2,3,4,5,6};
int dp[7] = {0,1,2,3,4,5,6};

void multiply(int a[10][10], int b[10][10])
{
    int c[10][10] = {};
    for(int i=1;i<=6;++i)
        for(int j=1;j<=6;++j)
            for(int k=1;k<=6;++k)
                (c[i][j] += a[i][k]*b[k][j]%mod) %= mod;
    copy(&c[0][0],&c[0][0]+100,&a[0][0]);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    if(n<=6)
    {
        cout << dp[n];
        return 0;
    }
    int a[10][10] = {};
    for(int i=2;i<=6;++i)
        a[i-1][i] = 1;
    for(int i=1;i<=6;++i)
        a[6][i] = 1;
    for(int i=1;i<=6;++i)
        matpow[0][i][i] = 1;
    for(int p=1;p<=64;++p)
    {
        for(int i=1;i<=6;++i)
            for(int j=1;j<=6;++j)
                matpow[p][i][j] = matpow[p-1][i][j];
        multiply(matpow[p],a);
    }
    for(int j=64;~j;--j)
        if((1LL<<j) & n)
        {
            int ndp[7] = {0,v[1],v[2],v[3],v[4],v[5],v[6]};
            for(int i=1;i<=6;++i)
                for(int k=1;k<=6;++k)
                    (v[i] += ndp[k]*matpow[j][k][i]%mod) %= mod;
        }
    cout << v[6];
}