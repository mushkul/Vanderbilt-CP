#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
const int INF = 1e9;

int n;
int row_req[MAXN];
int col_req[MAXN];
int grid[MAXN][MAXN];
int chosen[MAXN][MAXN];

bool solve(int r) {
    if (r == n) {
        for (int j = 0; j < n; j++) {
            int col_sum = 0;
            for (int i = 0; i < n; i++) {
                col_sum += chosen[i][j];
            }
            if (col_sum != col_req[j]) return false;
        }
        return true;
    }
    
    vector<pair<int, int>> candidates;
    for (int j = 0; j < n; j++) {
        candidates.push_back({grid[r][j], j});
    }
    
    sort(candidates.rbegin(), candidates.rend());
    
    int row_left = row_req[r];
    vector<int> current_choice(n);
    
    for (int k = 0; k < row_left; k++) {
        current_choice[candidates[k].second] = 1;
    }
    
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != row_req[r]) continue;
        
        vector<int> choice(n);
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) choice[j] = 1;
        }
        
        bool valid = true;
        for (int j = 0; j < n; j++) {
            if (choice[j] && current_choice[j]) {
                valid = false;
                break;
            }
        }
        
        if (!valid) continue;
        
        for (int j = 0; j < n; j++) {
            chosen[r][j] = choice[j];
        }
        
        if (solve(r + 1)) return true;
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> row_req[i];
    }
    
    for (int j = 0; j < n; j++) {
        cin >> col_req[j];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    memset(chosen, 0, sizeof(chosen));
    
    if (solve(0)) {
        int total_coins = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (chosen[i][j]) {
                    total_coins += grid[i][j];
                }
            }
        }
        
        cout << total_coins << "\n";
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (chosen[i][j] ? 'X' : '.');
            }
            cout << "\n";
        }
    } else {
        cout << "-1\n";
    }
    
    return 0;
}