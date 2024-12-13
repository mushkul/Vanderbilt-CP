#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long left = 1, right = (long long)n * n;
    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long count = 0;
        
        for (int i = 1; i <= n; i++) {
            count += min((long long)n, mid / i);
        }
        
        if (count < (long long)n * n / 2 + 1) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    cout << left << endl;
    
    return 0;
}