#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long prev = 0;
    long long moves = 0;
    
    for(long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        if(i > 0 && x < prev) {
            moves += prev - x;
            x = prev;
        }
        prev = x;
    }
    
    cout << moves;
    return 0;
}