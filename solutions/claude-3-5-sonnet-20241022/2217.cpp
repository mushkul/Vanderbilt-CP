#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n+1);
    vector<int> pos(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    auto count_rounds = [&]() {
        int rounds = 1;
        for(int i = 1; i < n; i++) {
            if(pos[i] > pos[i+1]) rounds++;
        }
        return rounds;
    };
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        
        int val1 = a[x], val2 = a[y];
        swap(a[x], a[y]);
        pos[val1] = y;
        pos[val2] = x;
        
        cout << count_rounds() << "\n";
    }
    
    return 0;
}