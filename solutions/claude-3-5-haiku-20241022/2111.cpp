#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    
    vector<int> a(n), b(m);
    vector<int> ways(2*k+1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int total_weight = a[i] + b[j];
            ways[total_weight]++;
        }
    }
    
    for (int w = 2; w <= 2*k; w++) {
        cout << ways[w] << " ";
    }
    
    return 0;
}