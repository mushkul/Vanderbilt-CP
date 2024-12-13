#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n>>x;
    vector<ll> s(n+1),f(n+1),t(n+1),g(n+1);
    for (int i=1; i<=n; i++) cin>>s[i];
    for (int i=1; i<=n; i++) cin>>f[i];
    g[0] = x;
    for (int i=1; i<=n; i++) {
        t[i] = t[i-1] + s[i]*g[i-1];
        g[i] = min(g[i-1], f[i]);
        for(int j=i-1; j>0 && (1<<(i-j))<=j; j--){
            t[i] = min(t[i], t[j] + s[i]*g[j] + (s[i] - s[j])*f[j]);
            g[i] = min(g[i], f[j]);
        }
    }
    cout << t[n] << "\n";
}