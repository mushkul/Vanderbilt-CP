#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    
    long long zeros = 0;
    for (long long i = 5; i <= n; i *= 5) {
        zeros += n/i;
    }
    
    cout << zeros << endl;
    return 0;
}