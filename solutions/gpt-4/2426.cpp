#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, n, x, y;
    cin>>a>>b>>n;

    vector<pair<ll,ll>> vec(n+1);
    for(ll i = 1; i <= n; i++) {
        cin>>x>>y;
        vec[i]={x-y, i};
    }

    vector<ll> prog(n+1);
    vector<ll> art(n+1);
    for(ll i = 1; i <= n; i++) {
        cin>>x>>y;
        prog[i]=x;
        art[i]=y;
    }

    sort(vec.begin()+1, vec.end());
    reverse(vec.begin()+1, vec.end());
    multiset<ll> skills;
    ll sum = 0;
    for(ll i = 1; i <= n; i++) {
        ll ind = vec[i].second;
        if(a > 0) {
            sum += prog[ind];
            skills.insert(prog[ind]);
            a--;
        }
        else
            sum += art[ind];
    }
    for(ll i = 1; i <= n; i++) {
        ll ind = vec[i].second;
        if(b && skills.empty()) break;
        if(b && *skills.begin() < art[ind]) {
            sum -= *skills.begin();
            skills.erase(skills.begin());
            sum += art[ind];
            b--;
        }
    }
    cout<<sum;
    return 0;
}