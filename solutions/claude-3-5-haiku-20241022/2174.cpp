#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    
    int steps = 0;
    while (n > 0) {
        int max_digit = 0;
        ll temp = n;
        while (temp > 0) {
            max_digit = max(max_digit, (int)(temp % 10));
            temp /= 10;
        }
        
        n -= max_digit;
        steps++;
    }
    
    cout << steps << endl;
    return 0;
}