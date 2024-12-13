#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> h(n);
    for(int i=0; i<n; ++i){
        cin >> h[i].first;
        h[i].second = i+1;
    }
    sort(h.begin(), h.end());
    multiset<pair<int, int>> rooms(h.begin(), h.end());
    for(int i=0; i<m; ++i){
        int r;
        cin >> r;
        auto it = rooms.lower_bound({r, 0});
        if(it == rooms.end()){
            cout << 0 << " ";
        } else {
            cout << it->second << " ";
            rooms.erase(it);
        }
    }

    return 0;
}