#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> forest(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        string row;
        cin >> row;
        for (int j = 1; j <= n; j++) {
            forest[i][j] = forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1] + (row[j-1] == '*');
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        int trees = forest[y2][x2] - forest[y1-1][x2] - forest[y2][x1-1] + forest[y1-1][x1-1];
        cout << trees << "\n";
    }

    return 0;
}