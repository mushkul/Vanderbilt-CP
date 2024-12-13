#include <bits/stdc++.h>
using namespace std;

long long solve(long long n, long long k) {
    if(k <= n / 2) return 2 * k;
    return 2 * solve((n + 1) / 2, (k - n / 2));
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long q, n, k;
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }

    return 0;
}