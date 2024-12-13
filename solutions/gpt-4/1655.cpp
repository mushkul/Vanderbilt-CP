#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0)a[i]^=a[i-1];  
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,a[i]);
        for(int j=0;j<i;j++){
            ans=max(ans,a[i]^a[j]);        
        }
    }
    cout<<ans<<"\n";
    return 0;
}