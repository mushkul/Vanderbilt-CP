#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    
    vector<ll> arr(n+1), diff(n+1);
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 2; i <= n; ++i){
        if(arr[i-1] > arr[i])
            diff[i] = arr[i-1] - arr[i];
        diff[i] += diff[i-1];
    }
    
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << diff[b] - diff[a] << "\n";
    }
    
    return 0;
}