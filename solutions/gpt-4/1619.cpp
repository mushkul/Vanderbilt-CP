#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v(2*n);

    for(int i = 0; i < n; i++){
        cin >> v[2*i].first >> v[2*i+1].first;
        v[2*i].second = 1;
        v[2*i+1].second = -1;
    }

    sort(v.begin(), v.end());

    int res = 0, x = 0;
    for(auto &i: v){
        x += i.second;
        res = max(res, x);
    }

    cout << res << "\n";
    return 0;
}