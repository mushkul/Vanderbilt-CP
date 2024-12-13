#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }
    
    long long steps = 0;
    for (int i = 0; i < n; i++) {
        steps += abs(diff[i]);
    }
    
    cout << steps / 2 << endl;
    
    return 0;
}