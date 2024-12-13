#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        int val;
        cin >> val;
        x[i] = x[i-1] + val;
    }
    
    long long max_sum = LLONG_MIN;
    multiset<long long> prefix_sums;
    
    for (int i = a; i <= n; ++i) {
        if (i > b) {
            prefix_sums.erase(prefix_sums.find(x[i-b-1]));
        }
        prefix_sums.insert(x[i-a]);
        max_sum = max(max_sum, x[i] - *prefix_sums.begin());
    }
    
    cout << max_sum << endl;
    return 0;
}