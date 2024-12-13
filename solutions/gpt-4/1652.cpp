#include<bits/stdc++.h>
using namespace std;

int n, q, prefix[1001][1001], y1, y2, x1, x2;

int main(){
    cin >> n >> q;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            char c;
            cin >> c;
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + (c == '*');
        }
    }
    while(q--){
        cin >> y1 >> x1 >> y2 >> x2;
        cout << prefix[y2][x2] - prefix[y2][x1-1] - prefix[y1-1][x2] + prefix[y1-1][x1-1] << "\n";
    }
    return 0;
}