#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> x(n + 1, 0), prefixSum(n + 1, 0), cost(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        if (i > 1) {
            cost[i] = max(0LL, x[i - 1] - x[i]);
        }
        prefixSum[i] = prefixSum[i - 1] + cost[i];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << prefixSum[b] - prefixSum[a] << '\n';
    }

    return 0;
}