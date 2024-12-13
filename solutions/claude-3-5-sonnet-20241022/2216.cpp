#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> pos(n+1);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pos[x] = i;
    }
    
    int rounds = 1;
    for(int i = 1; i < n; i++) {
        if(pos[i] > pos[i+1]) rounds++;
    }
    
    cout << rounds << "\n";
    
    return 0;
}