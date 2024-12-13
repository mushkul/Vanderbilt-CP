#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n % 6 == 0) cout << "second\n"; 
        else cout << "first\n"; 
    }
    return 0;
}