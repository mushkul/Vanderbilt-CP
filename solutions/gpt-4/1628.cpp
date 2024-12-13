#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, x, arr[40], h1, h2, ways=0;
unordered_map<ll, ll> frq1, frq2;

void solve(ll i, ll sum, ll h, bool flag)
{
    if(i==h)
    {
        if(flag)
            frq1[sum]++;
        else
        {
            if(frq1.find(x - sum) != frq1.end())
                ways+=frq1[x - sum];
        }
        return;
    }

    solve(i+1, sum, h, flag);
    solve(i+1, sum + arr[i], h, flag);
}


int main()
{
    cin >> n >> x;

    for(ll i=0; i<n; i++)
        cin >> arr[i];

    h1 = n/2;
    h2 = n - h1;

    solve(0, 0, h1, 1);
    solve(h1, 0, n, 0);

    cout<<ways<<"\n";
    return 0;
}