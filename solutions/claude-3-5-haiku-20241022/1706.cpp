#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int parent[MAXN];
int rank_[MAXN];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSet(int x, int y) {
    int px = find(x);
    int py = find(y);
    
    if (px == py) return;
    
    if (rank_[px] < rank_[py])
        swap(px, py);
    
    parent[py] = px;
    
    if (rank_[px] == rank_[py])
        rank_[px]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_[i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unionSet(a, b);
    }
    
    vector<int> groups(n + 1);
    for (int i = 1; i <= n; i++)
        groups[find(i)]++;
    
    vector<bool> possible(n + 1, false);
    possible[0] = true;
    
    for (int size : groups) {
        if (size == 0) continue;
        
        vector<bool> new_possible(n + 1, false);
        
        for (int i = 0; i <= n; i++) {
            if (!possible[i]) continue;
            new_possible[i] = true;
            new_possible[i + size] = true;
        }
        
        possible = new_possible;
    }
    
    for (int i = 1; i <= n; i++)
        cout << (possible[i] ? '1' : '0');
    
    cout << '\n';
    
    return 0;
}