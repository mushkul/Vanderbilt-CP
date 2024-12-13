#include <iostream>
#include <cmath>
using namespace std;

void towerOfHanoi(int n, int from, int aux, int to) {
    if (n == 0) return;
    
    towerOfHanoi(n-1, from, to, aux);
    cout << from << " " << to << "\n";
    towerOfHanoi(n-1, aux, from, to);
}

int main() {
    int n;
    cin >> n;
    
    cout << (1<<n) - 1 << "\n";
    towerOfHanoi(n, 1, 2, 3);
    
    return 0;
}