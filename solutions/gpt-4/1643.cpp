#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    vector<ll> x(n);
    for(int i = 0; i<n; i++) cin>>x[i];

    ll ans=x[0], sum=0;
    for(int i=0; i<n; i++){
        if(sum>0) sum+=x[i];
        else sum=x[i];
        ans=max(ans, sum);
    }
    cout << ans;
    return 0;
}