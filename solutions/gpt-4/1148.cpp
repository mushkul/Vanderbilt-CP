#include<bits/stdc++.h>
using namespace std;

int n,m,i,j,L[1009][1009],U[1009][1009],dp[1009][1009][2],vis[1009][1009][2],MOD=1000000007;
char c[1009][1009];

int add(int a,int b){
    a+=b;
    if(a>=MOD) a-=MOD;
    return a;
}

int val(int i,int j,int l,int u){
    if(i<1||i>n||j<1||j>m||l!=L[i][j]||u!=U[i][j]) return 0;
    int &ret=dp[i][j][l==j];
    if(vis[i][j][l==j]) return ret;
    vis[i][j][l==j]=1;
    return ret=add(add(val(i,j-1,l,u),val(i-1,j,l,u)),add(val(i,j-1,l,j),val(i-1,j,i,j)));
}

int main(){
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            cin>>c[i][j];
            L[i][j]=c[i][j]=='.'?L[i][j-1]:j-1;
            U[i][j]=c[i][j]=='.'?U[i-1][j]:i-1;
        }
    dp[1][1][1]=1; vis[1][1][1]=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            printf("%d ",add(val(i,j,L[i][j],U[i][j]),add(val(i,j,i,j),val(i,j,L[i][j],j))));
    puts("");
    return 0;
}