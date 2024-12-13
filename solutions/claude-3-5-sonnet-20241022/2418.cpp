#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
int n, m, y1, x1, y2, x2;
bool vis[MAXN][MAXN];
string path;
bool found;

bool valid(int y, int x) {
    return y >= 1 && y <= n && x >= 1 && x <= m && !vis[y][x];
}

void dfs(int y, int x) {
    if (y == y2 && x == x2) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (vis[i][j]) cnt++;
                
        if (cnt == n*m) found = true;
        return;
    }

    int dy[] = {-1, 1, 0, 0};
    int dx[] = {0, 0, -1, 1};
    char dir[] = {'U', 'D', 'L', 'R'};

    for (int k = 0; k < 4; k++) {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if (valid(ny, nx)) {
            vis[ny][nx] = true;
            path += dir[k];
            dfs(ny, nx);
            if (found) return;
            path.pop_back();
            vis[ny][nx] = false;
        }
    }
}

void solve() {
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    
    memset(vis, false, sizeof(vis));
    path = "";
    found = false;
    
    vis[y1][x1] = true;
    dfs(y1, x1);

    if (found) {
        cout << "YES\n" << path << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}