#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> h(n), s(n), k(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) cin >> k[i];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = x; j >= 0; --j) {
            for (int copies = 1; copies <= k[i] && copies * h[i] <= j; ++copies) {
                dp[j] = max(dp[j], dp[j - copies * h[i]] + copies * s[i]);
            }
        }
    }

    cout << dp[x] << endl;
    return 0;
}