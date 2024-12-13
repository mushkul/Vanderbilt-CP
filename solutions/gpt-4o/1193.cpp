#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Cell {
    int x, y;
    char dir;
};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const char moves[] = {'U', 'D', 'L', 'R'};

bool is_valid(int x, int y, int n, int m, vector<string>& map, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && map[x][y] != '#' && !visited[x][y];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    pair<int, int> start, end;
    for (int i = 0; i < n; ++i) {
        cin >> map[i];
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 'A') start = {i, j};
            if (map[i][j] == 'B') end = {i, j};
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<Cell>> prev(n, vector<Cell>(m, {-1, -1, ' '}));
    queue<Cell> q;

    q.push({start.first, start.second, 'S'});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        Cell current = q.front();
        q.pop();

        if (current.x == end.first && current.y == end.second) {
            cout << "YES" << endl;
            string path;
            Cell backtrace = current;

            while (backtrace.dir != 'S') {
                path += backtrace.dir;
                backtrace = prev[backtrace.x][backtrace.y];
            }
            
            reverse(path.begin(), path.end());
            cout << path.size() << endl;
            cout << path << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (is_valid(nx, ny, n, m, map, visited)) {
                visited[nx][ny] = true;
                prev[nx][ny] = {current.x, current.y, moves[i]};
                q.push({nx, ny, moves[i]});
            }
        }
    }
    
    cout << "NO" << endl;
    return 0;
}