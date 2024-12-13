#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool canWrite(long long x, long long n) {
    vector<int> digitCount(10, 0);
    for (long long i = 1; i <= x; ++i) {
        long long num = i;
        while (num > 0) {
            digitCount[num % 10]++;
            if (digitCount[num % 10] > n) return false;
            num /= 10;
        }
    }
    return true;
}

int main() {
    long long n;
    cin >> n;
    
    long long left = 1, right = 2e18, lastValid = 1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (canWrite(mid, n)) {
            lastValid = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << lastValid << endl;
    return 0;
}