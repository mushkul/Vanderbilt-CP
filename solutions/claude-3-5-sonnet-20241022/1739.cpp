#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int bit[MAXN][MAXN];
int n, q;
vector<string> forest;

void update(int y, int x, int val) {
    for(int i = y; i <= n; i += i & -i)
        for(int j = x; j <= n; j += j & -j)
            bit[i][j] += val;
}

int query(int y, int x) {
    int sum = 0;
    for(int i = y; i > 0; i -= i & -i)
        for(int j = x; j > 0; j -= j & -j)
            sum += bit[i][j];
    return sum;
}

int getSum(int y1, int x1, int y2, int x2) {
    return query(y2, x2) - query(y2, x1-1) - query(y1-1, x2) + query(y1-1, x1-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> q;
    forest.resize(n+1);
    
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        forest[i] = "." + s;
    }
    
    memset(bit, 0, sizeof(bit));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(forest[i][j] == '*') {
                update(i, j, 1);
            }
        }
    }
    
    while(q--) {
        int type;
        cin >> type;
        
        if(type == 1) {
            int y, x;
            cin >> y >> x;
            if(forest[y][x] == '.') {
                forest[y][x] = '*';
                update(y, x, 1);
            } else {
                forest[y][x] = '.';
                update(y, x, -1);
            }
        } else {
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << getSum(y1, x1, y2, x2) << "\n";
        }
    }
    
    return 0;
}