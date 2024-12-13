#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cubes(n);
    
    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
    }
    
    vector<int> towers;
    
    for (int cube : cubes) {
        auto it = upper_bound(towers.begin(), towers.end(), cube);
        
        if (it == towers.end()) {
            towers.push_back(cube);
        } else {
            *it = cube;
        }
    }
    
    cout << towers.size() << endl;
    
    return 0;
}