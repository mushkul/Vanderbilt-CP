#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    double expected_max = 0;
    for (int x = 1; x <= k; x++) {
        double prob_max_less = pow((x - 1.0) / k, n);
        expected_max += x * (1 - prob_max_less);
    }
    
    cout << fixed << setprecision(6) << expected_max << endl;
    
    return 0;
}