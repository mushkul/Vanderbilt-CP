#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n), pos(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i]--;
        pos[arr[i]] = i;
    }

    vector<vector<int>> rounds;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i] && pos[i] != i) {
            vector<int> cycle;
            int current = i;
            while (!visited[current]) {
                cycle.push_back(current);
                visited[current] = true;
                current = pos[current];
            }
            if (cycle.size() > 1) rounds.push_back(cycle);
        }
    }

    cout << rounds.size() << endl;
    for (auto &cycle : rounds) {
        cout << cycle.size() - 1 << endl;
        for (int i = 0; i < cycle.size() - 1; ++i) {
            cout << cycle[i] + 1 << " " << cycle[i + 1] + 1 << endl;
            swap(arr[cycle[i]], arr[cycle[i+1]]);
        }
    }
    
    return 0;
}