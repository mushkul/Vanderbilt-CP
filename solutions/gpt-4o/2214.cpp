#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    
    int prefix_len = 0;
    while (k >= prefix_len && prefix_len < n) {
        k -= prefix_len;
        prefix_len++;
    }
    
    for (int i = 0; i < prefix_len; i++) {
        p[i] = n - i;
    }
    for (int i = prefix_len; i < n; i++) {
        p[i] = i - prefix_len + 1;
    }
    
    if (k > 0) {
        swap(p[prefix_len - k - 1], p[prefix_len]);
    }
    
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    
    return 0;
}