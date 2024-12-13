#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=n-2;i>=0;--i) a[i]^=a[i+1];
    cout<<a[0];
    return 0;
}