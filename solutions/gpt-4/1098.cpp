#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int res = 0;
        for (int i = 0; i < n; ++i) res += a[i] % 4;
        if (res % 4 == 0) cout << "second" << "\n";
        else cout << "first" << "\n";
    }
    return 0;
}