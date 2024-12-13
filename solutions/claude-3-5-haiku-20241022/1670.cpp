#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> target = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> grid(3, vector<int>(3));
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> grid[i][j];
    
    map<vector<vector<int>>, int> dist;
    queue<vector<vector<int>>> q;
    
    dist[grid] = 0;
    q.push(grid);
    
    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        
        if (curr == target) {
            cout << dist[curr] << endl;
            return 0;
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                // Horizontal swaps
                if (j < 2) {
                    auto next = curr;
                    swap(next[i][j], next[i][j+1]);
                    if (dist.count(next) == 0) {
                        dist[next] = dist[curr] + 1;
                        q.push(next);
                    }
                }
                
                // Vertical swaps
                if (i < 2) {
                    auto next = curr;
                    swap(next[i][j], next[i+1][j]);
                    if (dist.count(next) == 0) {
                        dist[next] = dist[curr] + 1;
                        q.push(next);
                    }
                }
            }
        }
    }
    
    return 0;
}