#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define F first
#define S second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, pii>> v;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int x;
            cin >> x;
            v.push_back({x, {i, j}});
        }
    }
    sort(v.begin(), v.end());
    vector<bool> t1(n+1, 0), t2(n+1, 0);
    vector<pii> ans(n+1);
    for(auto x : v) {
        if(!t1[x.S.F] && !t2[x.S.S]) {
            t1[x.S.F]=1;
            t2[x.S.S]=1;
            ans[x.S.S]={x.S.F, x.S.S};
        }
    }
    int sum = 0;
    for(int i=1; i<=n; i++)
        sum += v[i-1].F;

    cout << sum << "\n";
    for(int i=1; i<=n; i++)
        cout << ans[i].F << " " << ans[i].S << "\n";
}