#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOGN = 20;
int up[MAXN][LOGN];
int n, q;

void binary_lifting(vector<int>& parent) {
    for(int v = 1; v <= n; v++) {
        up[v][0] = parent[v];
    }
    
    for(int j = 1; j < LOGN; j++) {
        for(int v = 1; v <= n; v++) {
            if(up[v][j-1] != -1) {
                up[v][j] = up[up[v][j-1]][j-1];
            } else {
                up[v][j] = -1;
            }
        }
    }
}

int get_kth_ancestor(int x, int k) {
    for(int j = LOGN-1; j >= 0; j--) {
        if(k & (1 << j)) {
            x = up[x][j];
            if(x == -1) return -1;
        }
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> q;
    vector<int> parent(n+1);
    parent[1] = -1;
    
    for(int i = 2; i <= n; i++) {
        cin >> parent[i];
    }
    
    binary_lifting(parent);
    
    while(q--) {
        int x, k;
        cin >> x >> k;
        cout << get_kth_ancestor(x, k) << '\n';
    }
    
    return 0;
}