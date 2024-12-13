#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    sort(weights.begin(), weights.end());
    
    int gondolas = 0;
    int left = 0, right = n - 1;
    
    while (left <= right) {
        if (left == right) {
            gondolas++;
            break;
        }
        
        if (weights[left] + weights[right] <= x) {
            left++;
            right--;
            gondolas++;
        } else {
            right--;
            gondolas++;
        }
    }
    
    cout << gondolas << endl;
    
    return 0;
}