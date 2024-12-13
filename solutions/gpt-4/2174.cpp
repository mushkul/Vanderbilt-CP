#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    int ans=0;
    while(n>0){
        int mx=0;
        for(char c : to_string(n))
            mx=max(mx, c-'0');
        n-=mx;
        ans++;
    }
    cout << ans;
}