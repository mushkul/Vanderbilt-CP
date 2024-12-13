#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ArrayOperations {
    vector<int> arr;
    vector<long long> prefixSum;

    void buildPrefixSum() {
        prefixSum.resize(arr.size() + 1, 0);
        for (size_t i = 1; i <= arr.size(); ++i) {
            prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
        }
    }

public:
    ArrayOperations(const vector<int>& initialArr) {
        arr = initialArr;
        buildPrefixSum();
    }

    void reverseSubarray(int a, int b) {
        reverse(arr.begin() + a - 1, arr.begin() + b);
        buildPrefixSum();
    }

    long long sumSubarray(int a, int b) {
        return prefixSum[b] - prefixSum[a - 1];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    ArrayOperations operations(arr);

    for (int i = 0; i < m; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            operations.reverseSubarray(a, b);
        } else if (t == 2) {
            cout << operations.sumSubarray(a, b) << "\n";
        }
    }

    return 0;
}