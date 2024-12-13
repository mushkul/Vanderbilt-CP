#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string directions = "DLRU";

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y];
}

string getPath(pair<int, int> start, pair<int, int> end) {
    string path;
    while (end != start) {
        pair<int, int> prev = parent[end.first][end.second];
        for (int i = 0; i < 4; i++) {
            if (prev.first + dx[i] == end.first && prev.second + dy[i] == end.second) {
                path += directions[i];
                break;
            }
        }
        end = prev;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<int, int>>(m));

    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;
    while (!q.empty() && !found) {
        pair<int, int> curr = q.front();
        q.pop();

        if (curr == end) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.first + dx[i];
            int ny = curr.second + dy[i];

            if (isValid(nx, ny)) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                parent[nx][ny] = curr;
            }
        }
    }

    if (found) {
        cout << "YES\n";
        string path = getPath(start, end);
        cout << path.length() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}