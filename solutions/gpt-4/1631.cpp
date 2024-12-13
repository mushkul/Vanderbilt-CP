#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> t(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>t[i];
        sum+=t[i];
    }
    sort(t.begin(),t.end());
    ll mx=t[n-1];
    ll other=sum-mx;
    cout<<max(sum,2*mx)<<"\n";
    return 0;
}