#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> top(n), bottom(n);
    for (int i = 0; i < n; ++i) cin >> top[i];
    for (int i = 0; i < n; ++i) cin >> bottom[i];

    int topDeficit = 0, bottomDeficit = 0, moves = 0;
    for (int i = 0; i < n; ++i) {
        topDeficit += top[i] - 1;
        bottomDeficit += bottom[i] - 1;
        moves += abs(topDeficit) + abs(bottomDeficit);
    }
    
    cout << moves << endl;
    return 0;
}