#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(),v.end());
    int ans=0;
    int end=0;
    for(auto p: v){
        if(!ans || p.second>=end){
            ans++;
            end=p.first;
        }
    }
    cout<<ans<<endl;
    return 0;
}