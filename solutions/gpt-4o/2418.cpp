#include <iostream>
#include <vector>
#include <string>
using namespace std;

void create_path(vector<string> &paths, int n, int m, int y1, int x1, int y2, int x2) {
    string path;
    bool left_to_right = true;

    for (int i = 0; i < n; ++i) {
        if (left_to_right) {
            for (int j = 0; j < m; ++j) {
                if (i == y1 - 1 && j == x1 - 1) continue;
                path += (i == y1 - 1 && j + 1 == x1) ? "" : "R";
            }
        } else {
            for (int j = m - 1; j >= 0; --j) {
                if (i == y1 - 1 && j == x1 - 1) continue;
                path += (i == y1 - 1 && j + 1 == x1) ? "" : "L";
            }
        }
        if (i != n - 1) {
            path += "D";
        }
        left_to_right = !left_to_right;
    }

    if (x1 != x2) {
        if (y1 != y2) {
            // empty path since we are already at the correct starting position
        } else {
            if (abs(x1 - x2) < m) {
                if (x1 < x2) {
                    path = path + string(m - (x2 - x1), 'L') + string(m - (x1 - 1), 'R');
                } else {
                    path = path + string(m - (x1 - x2), 'R') + string(m - (x1 - 1), 'L');
                }
            }
        }
    } else {
        if (y1 < y2) {
            path = string(m - 1, 'R') + path;
        } else {
            path = string(m - 1, 'L') + string(n - 1, 'U') + path;
        }
    }

    paths.push_back(path);
}

int main() {
    int t;
    cin >> t;
    vector<string> results(t);
    vector<string> paths;

    for (int test = 0; test < t; ++test) {
        int n, m, y1, x1, y2, x2;
        cin >> n >> m >> y1 >> x1 >> y2 >> x2;

        if ((n <= 1 && m <= 1) || ((n * m) % 2 != 0)) {
            results[test] = "NO";
            continue;
        }

        results[test] = "YES";
        create_path(paths, n, m, y1, x1, y2, x2);
    }

    for (int i = 0; i < t; ++i) {
        cout << results[i] << endl;
        if (!paths[i].empty()) {
            cout << paths[i] << endl;
        }
    }

    return 0;
}