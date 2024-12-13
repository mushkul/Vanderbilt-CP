#include <bits/stdc++.h>
using namespace std;

string path;
bool visited[7][7];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int total_paths = 0;

bool is_valid(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7 && !visited[x][y];
}

void solve(int x, int y, int step) {
    if (x == 6 && y == 0) {
        if (step == 48) total_paths++;
        return;
    }

    if (step >= 48) return;

    char current = path[step];
    
    for (int i = 0; i < 4; i++) {
        if (current != '?' && current != "DURL"[i]) continue;
        
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (!is_valid(nx, ny)) continue;
        
        visited[nx][ny] = true;
        solve(nx, ny, step + 1);
        visited[nx][ny] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> path;
    visited[0][0] = true;
    solve(0, 0, 0);
    
    cout << total_paths << "\n";
    
    return 0;
}