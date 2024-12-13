#include <iostream>
#include <string>

using namespace std;

long long dp[49][7][7][1 << 7 | 1];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char mv[4] = {'D', 'R', 'U', 'L'};

long long count_paths(string &s, int i, int x, int y, int bm) {
    if (x < 0 || y < 0 || x >= 7 || y >= 7 || bm >> y & 1) return 0;
    if (i == 48) return x == 6 && y == 0;
    if (dp[i][x][y][bm] != -1) return dp[i][x][y][bm];
    long long res = 0;
    bm |= 1 << y;
    if (s[i] == '?') {
        if (!((bm << 1 & bm || bm >> 1 & bm) && x - dx[0] < 7 && x - dx[0] >= 0))
            res += count_paths(s, i + 1, x + dx[0], y + dy[0], bm >> (y == 6));
        for (int d = 1; d < 4; d++)
            res += count_paths(s, i + 1, x + dx[d], y + dy[d], bm);
    }
    else {
        for (int d = 0; d < 4; d++) {
            if (s[i] != mv[d]) continue;
            if (!((bm << 1 & bm || bm >> 1 & bm) && x - dx[d] < 7 && x - dx[d] >= 0) || d == 1)
                res = count_paths(s, i + 1, x + dx[d], y + dy[d], bm);
        }
    }
    return dp[i][x][y][bm] = res;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 49; i++)
        for (int j = 0; j < 7; j++)
            for (int k = 0; k < 7; k++)
                for (int l = 0; l < 129; l++)
                    dp[i][j][k][l] = -1;
    cout << count_paths(s, 0, 0, 0, 0);
}