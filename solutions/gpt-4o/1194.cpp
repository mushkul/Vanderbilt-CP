#include <bits/stdc++.h>
using namespace std;

struct Position {
    int x, y, dist;
    string path;
};

const int MAXN = 1000;
int n, m, start_x, start_y;
string grid[MAXN];
bool visited[MAXN][MAXN];
queue<Position> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char moveChars[] = {'D', 'U', 'R', 'L'};

bool isBoundary(int x, int y) {
    return x == 0 || x == n-1 || y == 0 || y == m-1;
}

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start_x = i;
                start_y = j;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                q.push({i, j, 0, ""});
                visited[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto [x, y, dist, path] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (isValid(nx, ny)) {
                visited[nx][ny] = true;
                q.push({nx, ny, dist+1, path + moveChars[k]});
            }
        }
    }

    memset(visited, false, sizeof(visited));
    q.push({start_x, start_y, 0, ""});
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        auto [x, y, dist, path] = q.front(); q.pop();
        if (isBoundary(x, y) && grid[x][y] != 'M') {
            cout << "YES\n" << path.size() << "\n" << path << "\n";
            return 0;
        }
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (isValid(nx, ny) && (!visited[nx][ny] || path.size() + 1 < q.front().dist)) {
                visited[nx][ny] = true;
                q.push({nx, ny, dist+1, path + moveChars[k]});
            }
        }
    }

    cout << "NO\n";
    return 0;
}