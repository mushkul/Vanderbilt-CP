#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
long long fact[2000010],inv[2000010];

long long pow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)res=res*a%MOD;
        b>>=1;
        a=a*a%MOD;
    } return res; 
}

long long C(int n,int m){
    if(m>n || m<0) return 0;
    return fact[n]*inv[m]%MOD*inv[n-m]%MOD;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0]=inv[0]=1;
    for(int i=1;i<=2e6;i++){
        fact[i]=fact[i-1]*i%MOD;
        inv[i]=pow(fact[i],MOD-2);
    }
    int n,m;
    cin>>n>>m;
    cout<<(C(n+m,n)-C(n+m,n-1)+MOD)%MOD;
    return 0;
}