#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct SparseTable {
    vector<vector<int>> table;
    vector<int> log;
    
    SparseTable(vector<int>& arr) {
        int n = arr.size();
        log.resize(n + 1);
        log[1] = 0;
        for (int i = 2; i <= n; i++)
            log[i] = log[i/2] + 1;
            
        int k = log[n] + 1;
        table.resize(n, vector<int>(k));
        
        for (int i = 0; i < n; i++)
            table[i][0] = arr[i];
            
        for (int j = 1; j < k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[i][j] = min(table[i][j-1], table[i + (1 << (j-1))][j-1]);
            }
        }
    }
    
    int query(int l, int r) {
        int j = log[r - l + 1];
        return min(table[l-1][j], table[r - (1 << j)][j]);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    SparseTable st(arr);
    
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << st.query(a, b) << "\n";
    }
    
    return 0;
}