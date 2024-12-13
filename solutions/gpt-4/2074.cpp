#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<ll> arr(n+1), prefix_sum(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
    for(int i=0;i<m;i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            reverse(arr.begin() + a,arr.begin() + b + 1);
            prefix_sum[0] = 0;
            for(int j=1;j<=n;j++){
                prefix_sum[j] = prefix_sum[j-1] + arr[j];
            }
        }else{
            cout << prefix_sum[b] - prefix_sum[a-1] << '\n';
        }
    }
    return 0;
}