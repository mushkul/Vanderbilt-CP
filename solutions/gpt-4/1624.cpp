#include <bits/stdc++.h>
using namespace std;

char table[8][8];
bool column[8], diag1[16], diag2[16];
int sols = 0;

void search(int y) {
    if (y == 8) {
        sols++;
        return;
    }
    for (int x = 0; x < 8; x++) {
        if (table[y][x] == '*') continue;
        if (column[x] || diag1[x+y] || diag2[x-y+7]) continue;
        column[x] = diag1[x+y] = diag2[x-y+7] = true;
        search(y + 1);
        column[x] = diag1[x+y] = diag2[x-y+7] = false;
    }
}

int main() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> table[i][j];
    search(0);
    cout << sols << endl;
    return 0;
}