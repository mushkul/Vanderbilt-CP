#include <bits/stdc++.h>
using namespace std;

const int N = 7;
string s;
bool vis[N][N];
int ans = 0;

bool valid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N && !vis[i][j];
}

void solve(int i, int j, int pos) {
    if(pos == 48) {
        if(i == 6 && j == 0) ans++;
        return;
    }
    
    if(i == 6 && j == 0) return;
    
    if(((i == 0 || i == 6) && valid(i, j+1) && valid(i, j-1)) || 
       ((j == 0 || j == 6) && valid(i+1, j) && valid(i-1, j)) ||
       (valid(i, j-1) && valid(i, j+1) && !valid(i+1, j) && !valid(i-1, j)) ||
       (valid(i-1, j) && valid(i+1, j) && !valid(i, j-1) && !valid(i, j+1)))
        return;
        
    vis[i][j] = true;
    
    if(s[pos] == '?' || s[pos] == 'D') {
        if(valid(i+1, j))
            solve(i+1, j, pos+1);
    }
    if(s[pos] == '?' || s[pos] == 'U') {
        if(valid(i-1, j))
            solve(i-1, j, pos+1);
    }
    if(s[pos] == '?' || s[pos] == 'L') {
        if(valid(i, j-1))
            solve(i, j-1, pos+1);
    }
    if(s[pos] == '?' || s[pos] == 'R') {
        if(valid(i, j+1))
            solve(i, j+1, pos+1);
    }
    
    vis[i][j] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    solve(0, 0, 0);
    cout << ans << "\n";
    
    return 0;
}