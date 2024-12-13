#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define int long long

int32_t main(){
    int n, ans=1;
    cin >> n;
    while(n--){
        ans = (ans*2)%MOD;
    }
    cout << ans;
    return 0;
}