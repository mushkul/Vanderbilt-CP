#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> teleport(n + 1);
    vector<int> cycles(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> teleport[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (cycles[i] != 0) continue;
        
        vector<int> path;
        unordered_map<int, int> visited;
        int current = i;
        
        while (visited.count(current) == 0) {
            visited[current] = path.size();
            path.push_back(current);
            current = teleport[current];
        }
        
        int cycle_start = visited[current];
        int cycle_length = path.size() - cycle_start;
        
        for (int j = 0; j < path.size(); j++) {
            int planet = path[j];
            if (j < cycle_start) {
                cycles[planet] = path.size();
            } else {
                cycles[planet] = cycle_length;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << cycles[i] << " ";
    }
    
    return 0;
}