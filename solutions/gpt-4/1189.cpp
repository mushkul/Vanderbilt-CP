#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n),b(n),diff(n);
    ll steps=0, need=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        diff[i] = a[i] - b[i];
        if(diff[i]<0){
            need -= diff[i]/2;
        }
        else{
            steps += diff[i]/2;
        }
    }

    if(steps >= need){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }

    return 0;
}