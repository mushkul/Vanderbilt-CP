#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char direction[] = {'D', 'U', 'R', 'L'};

int n, m;
char grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
bool monster_dist[MAX_N][MAX_N];
int parent[MAX_N][MAX_N];

bool is_boundary(int x, int y) {
    return x == 0 || x == n-1 || y == 0 || y == m-1;
}

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && !visited[x][y];
}

void monster_bfs() {
    queue<pair<int,int>> q;
    memset(monster_dist, false, sizeof(monster_dist));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 'M') {
                q.push({i, j});
                monster_dist[i][j] = true;
            }
        }
    }

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(is_valid(nx, ny) && !monster_dist[nx][ny]) {
                monster_dist[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

bool player_bfs(int start_x, int start_y) {
    queue<pair<int,int>> q;
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if(is_boundary(x, y) && !monster_dist[x][y]) {
            return true;
        }

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(is_valid(nx, ny) && !monster_dist[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = true;
                parent[nx][ny] = k;
            }
        }
    }

    return false;
}

void print_path(int x, int y) {
    vector<char> path;
    while(parent[x][y] != -1) {
        int k = parent[x][y];
        path.push_back(direction[k]);
        x -= dx[k];
        y -= dy[k];
    }
    reverse(path.begin(), path.end());

    cout << "YES\n";
    cout << path.size() << "\n";
    for(char c : path) cout << c;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int start_x, start_y;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                start_x = i;
                start_y = j;
            }
        }
    }

    monster_bfs();
    
    if(player_bfs(start_x, start_y)) {
        print_path(start_x, start_y);
    } else {
        cout << "NO\n";
    }

    return 0;
}