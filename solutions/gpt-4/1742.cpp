#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;

int n;
map<ii, int> mp;
ii pos;
int cur = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    mp[pos] = 0;
    for (int i=0; i<n; i++) {
        char dir; int len;
        cin >> dir >> len;
        for (int j=0; j<len; j++) {
            if(dir == 'U') pos.first++;
            if(dir == 'D') pos.first--;
            if(dir == 'L') pos.second--;
            if(dir == 'R') pos.second++;
            cur++;
            if(mp.count(pos)) {
                cout << cur - 1 << "\n";
                return 0;
            }
            mp[pos] = cur;
        }
    }
    cout << cur << "\n";
    return 0;
}