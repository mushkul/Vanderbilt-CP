#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5+5;
vector<int> h(MAX), s(MAX);
int dp[MAX];
int n, x;

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = x; j >= h[i]; j--) {
            for (int rep = 1; rep <= k and h[i] * rep <= j; rep++) {
                dp[j] = max(dp[j], dp[j - h[i] * rep] + s[i] * rep);
            }
        }
    }
    cout << dp[x];
    return 0;
}