#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long minDifference(int index, long long group1, long long group2, const vector<int>& weights) {
    if (index == weights.size()) {
        return abs(group1 - group2);
    }
    return min(minDifference(index + 1, group1 + weights[index], group2, weights),
               minDifference(index + 1, group1, group2 + weights[index], weights));
}

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    cout << minDifference(0, 0, 0, weights) << endl;
    return 0;
}