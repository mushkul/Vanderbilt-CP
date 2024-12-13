#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n + 1);
    vector<int> pos(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }
    
    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i - 1] > pos[i]) {
            rounds++;
        }
    }
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        
        int x = arr[a];
        int y = arr[b];
        
        if (x > y) swap(x, y);
        
        vector<int> affected = {x, y, x - 1, x + 1, y - 1, y + 1};
        
        for (int val : affected) {
            if (val < 1 || val > n) continue;
            
            bool before = (pos[val - 1] > pos[val]);
            
            swap(arr[a], arr[b]);
            swap(pos[x], pos[y]);
            
            bool after = (pos[val - 1] > pos[val]);
            
            if (before != after) {
                rounds += (after ? 1 : -1);
            }
        }
        
        cout << rounds << '\n';
    }
    
    return 0;
}