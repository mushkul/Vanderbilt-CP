#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solve(vector<long long>& machines, long long target) {
    long long left = 0, right = 1e18;
    
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long products = 0;
        
        for (long long machine : machines) {
            products += mid / machine;
            
            if (products >= target) break;
        }
        
        if (products >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    long long n, t;
    cin >> n >> t;
    
    vector<long long> machines(n);
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }
    
    cout << solve(machines, t) << endl;
    
    return 0;
}