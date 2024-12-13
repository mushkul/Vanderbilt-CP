#include <iostream>
#include <vector>
using namespace std;

const int N = 7;
const int LEN = 48;
string path;
int grid[N][N] = {};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string dir = "UDLR";
int result = 0;

void search(int x, int y, int step) {
    if (x == N - 1 && y == 0) {
        if (step == LEN) result++;
        return;
    }
    
    if (step == LEN) return;
    
    grid[x][y] = 1;
    
    char current = path[step];
    for (int i = 0; i < 4; ++i) {
        if (current == '?' || current == dir[i]) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !grid[nx][ny]) {
                search(nx, ny, step + 1);
            }
        }
    }    
    grid[x][y] = 0;
}

int main() {
    cin >> path;
    search(0, 0, 0);
    cout << result << endl;
    return 0;
}