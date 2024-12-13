#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m1[200005], m2[200005];
    cin >> n;
    vector<pp> v, w;
    for(int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x, -y));
        w.push_back(make_pair(y,x));
    }
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    int maxx = v[0].second, minn = w[0].first;
    for(int i=0; i<n; i++) {
        maxx = min(maxx, v[i].second);
        minn = max(minn, w[i].first);
        m1[-maxx] = (v[i].second == maxx);
        m2[w[i].second] = (w[i].first == minn);
    }
    for(auto a : v)
        cout << m1[a.second] << ' ';
    cout << '\n';
    for(auto a : v)
        cout << m2[-a.second] << ' ';
    return 0;
}