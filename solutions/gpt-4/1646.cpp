#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxN = 2e5;
ll prefixSum[mxN+10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>prefixSum[i];
        prefixSum[i] += prefixSum[i-1];
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<prefixSum[b]-prefixSum[a-1]<<"\n";
    }
    return 0;
}