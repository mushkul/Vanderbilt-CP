#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    long long current_sum = 0;
    int subarrays = 1; 
    for (int i = 0; i < 2 * n; ++i) {
        current_sum += x[i % n];
        if (current_sum > k) {
            ++subarrays;
            current_sum = x[i % n];
        }
    }

    cout << subarrays << endl;
    return 0;
}