#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin>>n>>q;
    int a[200005];
    multiset<int> s;
    for(int i=1; i<=n; i++){ 
        cin>>a[i]; 
        s.insert(a[i]);
    }
    while(q--){
        char opt;
        cin >> opt;
        if(opt=='?'){
            int l,r;
            cin>>l>>r;
            auto L=s.lower_bound(l);
            auto R=s.upper_bound(r);
            cout<<distance(L,R)<<"\n";
        }
        else {
            int i, x;
            cin >> i >> x ;
            s.erase(s.find(a[i]));
            a[i]=x;
            s.insert(a[i]);
        }
    }
}