#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9+7;
const int MAXN = 505;
 
int n;
char grid[MAXN][MAXN];
vector<int> g[MAXN];
bool used[MAXN];
int match[MAXN];
 
bool try_kuhn(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int u : g[v]) {
        if (match[u] == -1 || try_kuhn(match[u])) {
            match[u] = v;
            return true;
        }
    }
    return false;
}
 
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    long long ans = 1;
    
    // First place A's
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool hasA = false;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'A') hasA = true;
        }
        if (!hasA) cnt++;
    }
    
    for (int pos = 0; pos < n; pos++) {
        for (int i = 0; i < n; i++) g[i].clear();
        
        vector<int> emptyRows;
        vector<int> emptyCols;
        
        for (int i = 0; i < n; i++) {
            bool hasA = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'A') hasA = true;
            }
            if (!hasA) emptyRows.push_back(i);
        }
        
        for (int j = 0; j < n; j++) {
            bool hasA = false;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 'A') hasA = true;
            }
            if (!hasA) emptyCols.push_back(j);
        }
        
        for (int i : emptyRows) {
            for (int j : emptyCols) {
                if (grid[i][j] == '.' && grid[i][j] != 'B') {
                    g[i].push_back(j);
                }
            }
        }
        
        int matching = 0;
        fill(match, match + MAXN, -1);
        
        for (int i : emptyRows) {
            fill(used, used + MAXN, false);
            if (try_kuhn(i)) matching++;
        }
        ans = (ans * matching) % MOD;
        
        if (pos < cnt) {
            // Place A's in matching
            for (int j : emptyCols) {
                if (match[j] != -1) {
                    grid[match[j]][j] = 'A';
                }
            }
        }
    }
    
    // Now place B's
    cnt = 0;
    for (int i = 0; i < n; i++) {
        bool hasB = false;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'B') hasB = true;
        }
        if (!hasB) cnt++;
    }
    
    for (int pos = 0; pos < n; pos++) {
        for (int i = 0; i < n; i++) g[i].clear();
        
        vector<int> emptyRows;
        vector<int> emptyCols;
        
        for (int i = 0; i < n; i++) {
            bool hasB = false;
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') hasB = true;
            }
            if (!hasB) emptyRows.push_back(i);
        }
        
        for (int j = 0; j < n; j++) {
            bool hasB = false;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 'B') hasB = true;
            }
            if (!hasB) emptyCols.push_back(j);
        }
        
        for (int i : emptyRows) {
            for (int j : emptyCols) {
                if (grid[i][j] == '.' && grid[i][j] != 'A') {
                    g[i].push_back(j);
                }
            }
        }
        
        int matching = 0;
        fill(match, match + MAXN, -1);
        
        for (int i : emptyRows) {
            fill(used, used + MAXN, false);
            if (try_kuhn(i)) matching++;
        }
        ans = (ans * matching) % MOD;
        
        if (pos < cnt) {
            for (int j : emptyCols) {
                if (match[j] != -1) {
                    grid[match[j]][j] = 'B';
                }
            }
        }
    }
    
    cout << ans << '\n';
    return 0;
}