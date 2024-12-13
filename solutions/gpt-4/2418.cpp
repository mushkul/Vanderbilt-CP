#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, sx, sy, ex, ey;
    cin >> n >> m >> sy >> sx >> ey >> ex;
    sy--; sx--; ey--; ex--;
    if(n > 1 && m > 1) {
        cout << "YES\n";
        for(int j = 0; j < m; j++) cout << 'R';
        for(int i = 0; i < n; i++) cout << 'D';
        for(int j = 0; j < m; j++) {
            if (i%2==0) cout << 'L';
            else cout << 'R';
        }
    } else {
        if(n == 1 && m == 1) {
            cout << (ey == 0 && ex == 0 ? "YES\n" : "NO\n");
        } else if(n == 1) {
            cout << (sy != 0 ? "NO\n" : "YES\n");
            for(int j = 1; j < m; j++) cout << 'R';
        } else if(m == 1) {
            cout << (sx != 0 ? "NO\n" : "YES\n");
            for(int i = 1; i < n; i++) cout << 'D';
        }
    }
    cout << '\n';
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}