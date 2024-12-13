#include <bits/stdc++.h>
using namespace std;
#define fo(i, n) for(int i=0; i<n; i++)
#define ll long long

vector<pair<ll,int>> col[60], row[60];
ll res[60][60];
string ans[60];
bool used[60][60];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int r[n], c[n];
    fo (i, n) cin >> r[i];
    fo (i, n) cin >> c[i];
    ll a[n][n];
    fo(i,n) fo(j,n) {
        cin >> a[i][j];
        col[j].push_back({a[i][j], i});
        row[i].push_back({a[i][j], j});
    }
    fo(i,n){
        ans[i] = string(n, '.');
        sort(row[i].rbegin(), row[i].rend());
        sort(col[i].rbegin(), col[i].rend());
        fo(j,r[i]) {
            ans[row[i][j].second][i] = 'X';
            res[row[i][j].second][i] = row[i][j].first;
            used[row[i][j].second][i] = 1;
            c[i]--;
        }
        if(c[i] < 0) {cout << "-1\n"; return 0;}
        fo(j,c[i]) {
            if(used[col[i][j].second][i]) j--;
            else {
                ans[col[i][j].second][i] = 'X';
                res[col[i][j].second][i] = col[i][j].first;
            }
        }
    }
    ll mx = 0;
    fo(i,n) fo(j,n)
        if(ans[i][j] == 'X') mx += res[i][j];
    cout << mx << endl;
    fo(i,n) cout << ans[i] << endl;
}