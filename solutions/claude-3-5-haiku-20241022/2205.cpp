#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < (1 << n); i++) {
        int grayCode = i ^ (i >> 1);
        string binary = bitset<16>(grayCode).to_string().substr(16 - n);
        cout << binary << endl;
    }
    
    return 0;
}