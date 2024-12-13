#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
    }

    vector<char> dp(n + 1, 'L');
    dp[0] = 'L';
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (i >= p[j] && dp[i - p[j]] == 'L') {
                dp[i] = 'W';
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dp[i];
    }
    cout << endl;

    return 0;
}