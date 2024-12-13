#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) p[i] = i + 1;
    
    int remaining = k;
    for (int i = n - 1; i >= 1 && remaining > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (remaining >= i - j) {
                swap(p[j], p[j + i - remaining]);
                remaining -= (i - j);
            }
            if (remaining == 0) break;
        }
    }
    
    for (int x : p) cout << x << " ";
    cout << endl;
    
    return 0;
}