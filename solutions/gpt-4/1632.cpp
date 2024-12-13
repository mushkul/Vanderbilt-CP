#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    
    cin>>n>>k;
    pair<int, int> time[n];

    for(int i=0; i<n; i++)
        cin>>time[i].second>>time[i].first;

    sort(time,time+n);
    multiset<int> club;

    for(int i=0; i<k; i++) 
        club.insert(0);
    
    int ans=0;
    for(int i=0; i<n; i++)
    {
        auto it=club.lower_bound(-time[i].second);
        if(it!=club.end())
        {
            club.erase(it);
            ans++;
        }
        club.insert(-time[i].first);
    }
    cout<<ans;
    return 0;
}