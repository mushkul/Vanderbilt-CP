#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int max_n = 2e5+10;

int a[max_n], n;
long long s[max_n];
set<pii> se;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> n >> q;

    for(int i = 1; i <= n; ++i) cin >> a[i];

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; ++i) s[i] = s[i-1]+a[i];

    se.insert({n+1,0});

    for(int i=n; i>=1; --i){
        se.insert({i, min(a[i]+1ll, se.lower_bound({i, 0})->second)});
    }

    for(int x,y; q--; ){
        cin >> x >> y;
        cout << ((se.lower_bound({y+1, 0})->second) <= s[y]-s[x-1] ? s[y]-s[x-1]+1 : se.lower_bound({x, 0})->second) << "\n";
    }

    return 0;
}