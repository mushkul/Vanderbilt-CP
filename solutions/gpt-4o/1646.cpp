#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        prefixSum[i] = prefixSum[i - 1] + x;
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << prefixSum[b] - prefixSum[a - 1] << endl;
    }
    return 0;
}