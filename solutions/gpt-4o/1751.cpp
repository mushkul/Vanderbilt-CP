#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i]--; // converting to zero-indexed
    }

    vector<int> result(n, -1);
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (result[i] != -1) continue;
        vector<int> path;
        int current = i;
        while (visited[current] == 0) {
            visited[current] = 1;
            path.push_back(current);
            current = t[current];
        }
        int cycle_length = -1;
        for (int j = 0; j < path.size(); j++) {
            if (path[j] == current) {
                cycle_length = path.size() - j;
                break;
            }
        }
        if (cycle_length == -1) continue;
        for (int j = 0; j < path.size(); j++) {
            if (j >= path.size() - cycle_length) {
                result[path[j]] = cycle_length;
            } else {
                result[path[j]] = cycle_length + (path.size() - j) - cycle_length;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}