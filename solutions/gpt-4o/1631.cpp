#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> times(n);
    long long total_time = 0, max_time = 0;
    for (int i = 0; i < n; i++) {
        cin >> times[i];
        total_time += times[i];
        max_time = max(max_time, times[i]);
    }
    cout << max(total_time, 2 * max_time) << endl;
    return 0;
}