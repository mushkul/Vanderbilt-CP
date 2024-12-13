#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
char dp[MAXN];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int a[k];
    for(int i=0;i<k;i++) scanf("%d",&a[i]);
    dp[0]='L';
    for(int i=1;i<=n;i++){
        dp[i]='L';
        for(int j=0;j<k;j++){
            if(i>=a[j]&&dp[i-a[j]]=='L') dp[i]='W';
        }
    }
    for(int i=1;i<=n;i++){
        printf("%c",dp[i]);
    }
    return 0;
}