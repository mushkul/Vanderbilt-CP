#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> prefixSum(n+1, vector<int>(n+1, 0));
    
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++) {
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1];
            if(s[j-1] == '*')
                prefixSum[i][j]++;
        }
    }
    
    while(q--) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        
        cout << prefixSum[y2][x2] - prefixSum[y2][x1-1] - prefixSum[y1-1][x2] + prefixSum[y1-1][x1-1] << endl;
    }
    
    return 0;
}