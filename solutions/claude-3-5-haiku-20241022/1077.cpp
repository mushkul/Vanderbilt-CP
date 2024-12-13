#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    auto solve = [&](int l, int r) {
        vector<int> window(arr.begin() + l, arr.begin() + r);
        sort(window.begin(), window.end());
        int median = window[k/2];
        ll cost = 0;
        for (int x : window) cost += abs(x - median);
        return cost;
    };

    for (int i = 0; i + k <= n; i++) {
        cout << solve(i, i + k) << " ";
    }
    
    return 0;
}