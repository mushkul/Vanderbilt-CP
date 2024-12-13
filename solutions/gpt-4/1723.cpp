#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define ll long long

ll edge[101][101], temp[101][101], res[101][101];

void multiply(bool indicator){
    ll multi[101][101] = {0};
    for(int i=1; i<=101; i++){
        for(int j=1; j<=101; j++){
            for(int p=1; p<=101; p++){
                if(indicator){
                    multi[i][j] = (multi[i][j] + res[i][p]*temp[p][j]) % MOD;
                }else{
                    multi[i][j] = (multi[i][j] + temp[i][p]*edge[p][j]) % MOD;
                }                
            }
        }
    }
    for(int i=1; i<=101; i++){
        for(int j=1; j<=101; j++){
            if(indicator){
                res[i][j] = multi[i][j];
            }else{
                temp[i][j] = multi[i][j];
            }
        }
    }
}

void solve(ll n, ll m, ll k){
    while (k){
        if(k % 2){
            multiply(1);
        }            
        multiply(0);
        k /= 2;
    }
    cout<<res[1][n];
}

int main(){
    ll n, m, k, a, b;
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        edge[a][b] = 1;
        temp[a][b] = 1;
    }
    for(int i=1; i<=n; i++){
        res[i][i] = 1;
    }
    solve(n, m, k);
    return 0; 
}