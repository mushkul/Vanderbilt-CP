#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin>>t;
    while(t--){
        ll y,x;
        cin>>y>>x;
        ll z = max(y,x);
        ll z2 = (z-1)*(z-1);
        if(y == z){
            if(z % 2){
                cout << z2+x << "\n";
            }else{
                cout << z2 + 2*z - x << "\n";
            }
        }else{
            if(z % 2){
                cout << z2 + 2*z - y << "\n";
            }else{
                cout << z2 + y << "\n";
            }
        }
    }
    
    return 0;
}