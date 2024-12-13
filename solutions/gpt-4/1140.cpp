#include<bits/stdc++.h>
using namespace std;
#define ios std::ios::sync_with_stdio(false)    
#define ll long long
typedef pair<ll,ll> ii;
#define f first
#define s second

const int max_n = 2e5+5;
ii event[max_n];
vector<ii> ts;
ll dp[max_n], a[max_n], b[max_n], p[max_n];

int main()
{
    ios;
    int n;
    cin>>n;
    for(int i=0;i<n;++i)    cin>>a[i]>>b[i]>>p[i];
    for(int i=0;i<n;++i)
    {
        ts.push_back({b[i], i});
        event[i] = {a[i], p[i]};
    }
    ts.push_back({0, -1});
    sort(ts.begin(), ts.end());
    ll mx = 0;
    for(int i=0;i<int(ts.size());++i)
    {
        while(!ts.empty() && ts.back().f > event[ts[i].s].f)
        {
            ii it = ts.back();
            ts.pop_back();
            dp[it.s] = max(dp[it.s], mx + it.f);
            mx = max(mx, dp[it.s]);
        }
        if(ts[i].s != -1)
            ts.push_back({event[ts[i].s].f-1, ts[i].s}); 
    }
    cout<<mx<<"\n";  
    return 0;
}