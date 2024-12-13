#include <iostream>
using namespace std;

long long solve(int y, int x) {
    long long current = 0;
    int row = 1, col = 1;
    
    while (row < y || col < x) {
        current++;
        if (row < y && col < x) {
            if (row <= col) row++;
            else col++;
        }
        else if (row < y) row++;
        else if (col < x) col++;
    }
    
    return current + 1;
}

int main() {
    int y, x;
    cin >> y >> x;
    cout << solve(y, x) << endl;
    return 0;
}