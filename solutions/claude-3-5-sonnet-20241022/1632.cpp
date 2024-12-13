#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> movies(n);
    for(int i = 0; i < n; i++) {
        cin >> movies[i].second >> movies[i].first;
    }
    
    sort(movies.begin(), movies.end());
    
    multiset<int> members;
    for(int i = 0; i < k; i++) {
        members.insert(0);
    }
    
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        auto it = members.upper_bound(movies[i].second);
        if(it != members.begin()) {
            it--;
            members.erase(it);
            members.insert(movies[i].first);
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}