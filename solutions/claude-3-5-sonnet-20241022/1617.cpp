#include <iostream>
using namespace std;
 
int main() {
    long long n;
    cin >> n;
    
    long long mod = 1000000007;
    long long result = 1;
    
    for(int i = 0; i < n; i++) {
        result = (result * 2) % mod;
    }
    
    cout << result;
    return 0;
}