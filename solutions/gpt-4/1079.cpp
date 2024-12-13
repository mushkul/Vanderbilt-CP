#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6+5;
const int mod = 1e9+7;
 
long long fac[N], inv[N];
 
long long modpow(long long a, long long b){
    if(b==0) return 1;
    long long res=modpow(a,b/2);
    if(b&1) return res*res%mod*a%mod;
    return res*res%mod;
}
 
void init(){
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=modpow(fac[i],mod-2);
    }
}
 
long long binomial(int a, int b){
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    int n; cin >> n;
    while(n--){
        int a,b; cin >> a >> b;
        cout << binomial(a,b) << '\n';
    }
    return 0;
}