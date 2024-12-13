#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int maxn = 1e3 + 10;
const int inf = 1e9;

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
vector<char> dir = {'D', 'U', 'R', 'L'};

int vis_m[maxn][maxn], vis_a[maxn][maxn], dis[maxn][maxn], par[maxn][maxn], n, m;
char g[maxn][maxn];
pii s, e;

bool is_valid(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= m || g[x][y] == '#' || vis_m[x][y] < inf) return false;
    return true;
}

void bfs_m()
{
    queue<pii> q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            vis_m[i][j] = inf;
        
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(g[i][j] == 'M')
                q.push({i, j}), vis_m[i][j] = 0;

    while(!q.empty())
    {
        pii u = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = u.first + dx[i], ny = u.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == '#' || vis_m[nx][ny] != inf) continue;
            vis_m[nx][ny] = vis_m[u.first][u.second] + 1;
            q.push({nx, ny});
        }
    }
}

void bfs_a()
{
    queue<pii> q;
    q.push(s);
    vis_a[s.first][s.second] = 0;
    
    while(!q.empty())
    {
        pii u = q.front();
        q.pop();

        for(int i=0; i<4; i++)
        {
            int nx = u.first + dx[i], ny = u.second + dy[i];
            if(!is_valid(nx, ny) || vis_a[nx][ny] != -1 || vis_m[nx][ny] <= vis_a[u.first][u.second] + 1) continue;
            vis_a[nx][ny] = vis_a[u.first][u.second] + 1;
            par[nx][ny] = i;
            q.push({nx, ny});
            if(nx == 0 || ny == 0 || nx == n-1 || ny == m-1)
            {
                e = {nx, ny};
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin >> g[i][j];
            if(g[i][j] == 'A') s = {i, j};
        }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            vis_a[i][j] = -1;

    bfs_m();
    bfs_a();

    if(vis_a[e.first][e.second] == -1)
    {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    cout << vis_a[e.first][e.second] << '\n';
    string path;
    while(e != s)
    {
        int dir = par[e.first][e.second];
        path.push_back(::dir[dir]);
        e = {e.first - dx[dir], e.second - dy[dir]};
    }
    reverse(path.begin(), path.end());
    cout << path << '\n';

    return 0;
}