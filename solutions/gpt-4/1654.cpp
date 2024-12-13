#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
typedef long long ll;

ll pre[21][MAX];
ll dp[MAX];
ll A[MAX];
ll p2[21];
int n;
int main(){
    p2[0]=1;
    for(int i=1;i<=20;i++) p2[i]=p2[i-1]*2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&A[i]),pre[int(log2(A[i]))][A[i]]++;
    for(int i=0;i<=20;i++)
        for(int j=0;j<=MAX-5;j++)
            if(j+p2[i]<=MAX-5) pre[i][j+p2[i]]+=pre[i][j];
    for(int i=1;i<=MAX-5;i++) dp[i]=dp[i-1]+(bool)pre[20][i];
    for(int i=1;i<=n;i++){
        ll x=A[i];
        ll bit=int(log2(A[i]));
        ll d1=pre[bit][x];
        ll d2=dp[x];
        ll d3=d1 - (x>1?dp[x-1]:0);
        printf("%lld %lld %lld\n",d1,d3,d2);
    }
    return 0;
}