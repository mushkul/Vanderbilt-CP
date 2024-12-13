#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, w[20], x;
P dp[1<<20];

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> w[i];
    dp[0] = {1, 0};
    for(int S = 1; S < (1<<n); S++) {
        dp[S] = {n+1, 0};
        for(int p = 0; p < n; p++) {
            if(S>>p&1) {
                P option = dp[S^(1<<p)];
                if(option.second+w[p] <= x) option.second += w[p];
                else option.first++, option.second = w[p];
                dp[S] = min(dp[S], option);
            }
        }
    }
    cout << dp[(1<<n)-1].first;
}