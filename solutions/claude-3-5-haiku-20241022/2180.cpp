#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> grid(2, vector<int>(n));
    vector<int> coins;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            for (int k = 0; k < grid[i][j]; k++) {
                coins.push_back(i * n + j);
            }
        }
    }
    
    sort(coins.begin(), coins.end());
    
    int moves = 0;
    for (int i = 0; i < coins.size(); i++) {
        int target = i;
        int current = coins[i];
        moves += abs(target / n - current / n) + abs(target % n - current % n);
    }
    
    cout << moves << endl;
    
    return 0;
}