#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
vector<pair<int,int> > ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],b[a[i]]=i;
    for(int i=1;i<=n;i++){
        if(a[i]==i) continue;
        if(b[i]-i+1<=n/2){
            ans.push_back({i,b[i]});
            int l=i,r=b[i];
            while(l<r) swap(a[l],a[r]),b[a[l]]=l,b[a[r]]=r,l++,r--;
        }
        else{
            ans.push_back({1,n});
            int l=1,r=n;
            while(l<r) swap(a[l],a[r]),b[a[l]]=l,b[a[r]]=r,l++,r--;
            ans.push_back({1,n});
            l=1,r=n;
            while(l<r) swap(a[l],a[r]),b[a[l]]=l,b[a[r]]=r,l++,r--;
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";
    return 0;
}