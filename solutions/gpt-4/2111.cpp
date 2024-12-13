#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 400009
ll apples[MAX], bananas[MAX], ans[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin>>k>>n>>m;
    ll a;
    for(ll i=0; i<n; i++)
    {
        cin>>a;
        apples[a]++;
    }
    for(ll i=0; i<m; i++)
    {
        cin>>a;
        bananas[a]++;
    }
    for(ll i=1; i<=2*k; i++)
    {
        for(ll j=max((ll)1,i-k); j<=min(i-1,k); j++)
        {
            ans[i]+=apples[j]*bananas[i-j];
        }
    }
    for(ll i=2; i<=2*k; i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}