#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin>>n>>x;
    vector<int> a(n+1);

    for(int i=1;i<=n;i++) cin>>a[i];

    long long sum = 0, ans = 0;
    map<long long, int> m;
    m[0] = 1;

    for(int i=1;i<=n;i++){
        sum += a[i];
        ans += m[sum - x];
        m[sum]++;
    }

    cout<<ans<<"\n";
    
    return 0;
}