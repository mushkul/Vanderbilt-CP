#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 505
int n, A=0, B=0, dp[N][N][N][2], a[N], b[N], s[N][2][2];
char c[N][N];

int solve(int x,int y,int z,int f){
    if(x==n+1) return y==B&&z==n;
    if(dp[x][y][z][f] != -1) return dp[x][y][z][f];
    int res=0;
    if(a[x]==3){
        if(f==0) res=solve(x+1,y,z,1);
        if(y<B) res=(res+solve(x+1,y+1,z,f))%mod;
    }
    else if(a[x]==1){
        if(f==0) res=solve(x+1,y+1,z,1);
        if(y<B) res=(res+solve(x+1,y+1,z,f))%mod;
    }
    else if(a[x]==2){
        if(f==1) res=solve(x+1,y,z+1,0);
        if(z<n) res=(res+solve(x+1,y,z+1,f))%mod;
    }
    else{
        if(f==0){
            if(y<B){
                res=(res+solve(x+1,y+1,z,1))%mod;
            }
            if(z<n){
                res=(res+solve(x+1,y,z+1,0))%mod;
            }
        }
        else{
            if(z<n){
                res=(res+solve(x+1,y,z+1,0))%mod;
            }
            if(y<B){
                res=(res+solve(x+1,y+1,z,1))%mod;
            }
        }
    }
    return dp[x][y][z][f]=res;
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",c[i]+1);
        for(int j=1;j<=n;j++){
            if(c[i][j]=='A') a[i]=1;
            else if(c[i][j]=='B') a[i]=2, b[j]=2;
            else if(b[j]!=2) b[j]=1;
        }
        if(a[i]==1) s[i][1][0]=1;
        if(a[i]==2) s[i][0][1]=1;
        if(a[i]==0) s[i][0][0]=1;
        for(int j=1;j<=i;j++){
            if(a[i]!=2) s[i][j][0]=(s[i][j][0]+s[i-1][j-1][0])%mod, s[i][j][1]=(s[i][j][1]+s[i-1][j-1][1])%mod;
            if(a[i]!=1) s[i][j][0]=(s[i][j][0]+s[i-1][j][0])%mod, s[i][j][1]=(s[i][j][1]+s[i-1][j][1])%mod;
        }
    }
    for(int i=1;i<=n;i++) A+=a[i]==1, B+=b[i]==2;
    memset(dp,-1,sizeof(dp));
    printf("%d",solve(1,0,0,0));
}