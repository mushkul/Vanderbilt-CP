#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 505;

int n;
char grid[MAXN][MAXN];
int rowA[MAXN], rowB[MAXN];
int colA[MAXN], colB[MAXN];

bool isValidGrid() {
    for (int i = 0; i < n; i++) {
        if (rowA[i] > 1 || rowB[i] > 1 || colA[i] > 1 || colB[i] > 1)
            return false;
    }
    return true;
}

int solve() {
    memset(rowA, 0, sizeof(rowA));
    memset(rowB, 0, sizeof(rowB));
    memset(colA, 0, sizeof(colA));
    memset(colB, 0, sizeof(colB));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'A') {
                rowA[i]++;
                colA[j]++;
            }
            if (grid[i][j] == 'B') {
                rowB[i]++;
                colB[j]++;
            }
        }
    }

    if (!isValidGrid())
        return 0;

    vector<pair<int, int>> emptyRows, emptyCols;

    for (int i = 0; i < n; i++) {
        if (rowA[i] == 0) emptyRows.push_back({i, 'A'});
        if (rowB[i] == 0) emptyRows.push_back({i, 'B'});
        if (colA[i] == 0) emptyCols.push_back({i, 'A'});
        if (colB[i] == 0) emptyCols.push_back({i, 'B'});
    }

    if (emptyRows.size() != emptyCols.size())
        return 0;

    long long ways = 1;
    for (int i = 0; i < emptyRows.size() / 2; i++)
        ways = (ways * 2) % MOD;

    return ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << solve() << "\n";
    return 0;
}