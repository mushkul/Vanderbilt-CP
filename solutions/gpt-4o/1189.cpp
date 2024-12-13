#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n), diff(n + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        diff[i + 1] = diff[i] + a[i] - b[i];
    }
    
    vector<long long> prefix_min(n + 1), prefix_max(n + 1);
    prefix_min[0] = diff[0];
    prefix_max[0] = diff[0];
    
    for (int i = 1; i <= n; ++i) {
        prefix_min[i] = min(prefix_min[i - 1], diff[i]);
        prefix_max[i] = max(prefix_max[i - 1], diff[i]);
    }
    
    long long total_diff = diff[n];
    long long result = LLONG_MAX;
    
    for (int i = 0; i < n; ++i) {
        long long delta = diff[i] * -1;
        long long shifted_min = prefix_min[n] - delta;
        long long shifted_max = prefix_max[n] - delta;
        result = min(result, max(abs(shifted_min), abs(shifted_max)));
    }
    
    cout << result << endl;
    return 0;
}