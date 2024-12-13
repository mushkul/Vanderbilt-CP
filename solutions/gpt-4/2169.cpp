#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll INF = 1e10;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    vector< pair <pll, int> > arr(n);
    vector<ll> contain(n);
    vector<int> contained(n);

    set<pair<pll, int>> s;
    for(int i=0; i<n; i++){
        cin>>arr[i].first.second>>arr[i].first.first;
        arr[i].first.first*=-1;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        arr[i].first.first*=-1;
        ll a=arr[i].first.second;
        ll b=arr[i].first.first;
        contained[arr[i].second] = s.size();

        while(!s.empty() && s.begin()->first.first<=b){
            contain[s.begin()->second]++;
            s.erase(s.begin());
        }

        s.insert({{b, a}, arr[i].second});
    }

    while(!s.empty()){
        contain[s.begin()->second]++;
        s.erase(s.begin());
    }

    for(int i=0; i<n; i++)
        contain[i]--;

    for(int i=0; i<n; i++)
        cout<<contain[i]<<" ";
    cout<<"\n";

    for(int i=0; i<n; i++)
        cout<<contained[i]<<" ";
    cout<<"\n";
}