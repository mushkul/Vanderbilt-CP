#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long solve(int n) {
    long long num = 0;
    for (int digits = 1; digits <= 18; digits++) {
        long long count[10] = {0};
        for (int d = 0; d < 10; d++) {
            count[d] = n;
        }
        
        long long current = 0;
        for (int d = 1; d <= digits; d++) {
            for (int digit = 0; digit < 10; digit++) {
                if (d == 1 && digit == 0) continue;
                
                if (count[digit] > 0) {
                    current = current * 10 + digit;
                    count[digit]--;
                    break;
                }
            }
        }
        
        if (current > num) {
            num = current;
        }
    }
    
    return num;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}