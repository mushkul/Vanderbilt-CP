#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    long long x, sum = 0, count = 0;
    cin >> n >> x;
    int a[n];
    unordered_map<long long, int> prefixSums;
    prefixSums[0] = 1;  // Add base case for sum starting from the first element

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
        if (prefixSums.find(sum - x) != prefixSums.end()) {
            count += prefixSums[sum - x];
        }
        prefixSums[sum]++;
    }

    cout << count << endl;
    return 0;
}