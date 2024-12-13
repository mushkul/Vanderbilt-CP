#include<bits/stdc++.h>
using namespace std;
int n;
pair<int,int> a[100005];
vector<pair<int,int>> ans;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    int l=1,r=n,mid;
    while(l<=r) {
        mid=(l+r)>>1;
        int tmp=0;
        for(int i=n;i>mid;i--)
            tmp+=min(a[i].first,mid);
        if(tmp>=mid*a[mid].first) {
            r=mid-1;
        } else l=mid+1;
    }
    for(int i=n;i>l;i--) {
        int tmp=min(a[i].first,l);
        for(int j=1;j<=tmp;j++)
            ans.push_back(make_pair(a[i].second,a[l-j+1].second));
    }
    int tmp=0;
    for(int i=l;i>=1;i--) {
        for(int j=1;j<=a[i].first-tmp;j++)
            ans.push_back(make_pair(a[i].second,a[i-j].second));
        tmp=a[i].first;
    }
    if(tmp!=l-1) cout<<"IMPOSSIBLE";
    else {
        cout<<ans.size()<<"\n";
        for(auto u:ans)
            cout<<u.first<<" "<<u.second<<"\n";
    }
    return 0;
}