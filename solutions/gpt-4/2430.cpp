C++
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s = "1";
    while(--n){
        if(n&1) s = "1"+s;
        else s = s+"1";
        n >>= 1;
    }
    cout<<s;
    return 0;
}