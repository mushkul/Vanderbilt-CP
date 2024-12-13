#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> signal(n);
    vector<int> mask(m);
    
    for (int i = 0; i < n; i++) {
        cin >> signal[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> mask[i];
    }
    
    vector<int> result(n + m - 1, 0);
    
    for (int i = 0; i < n + m - 1; i++) {
        for (int j = 0; j < m; j++) {
            int sigIndex = i - j;
            if (sigIndex >= 0 && sigIndex < n) {
                result[i] += signal[sigIndex] * mask[j];
            }
        }
    }
    
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}