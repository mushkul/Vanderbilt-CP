#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k, p[25];
ll res = 0;

void count(int idx, ll lcm, int cnt) {
    if (lcm > n) return;
    if (cnt % 2 == 1) res += n / lcm;
    else res -= n / lcm;
    for (int i = idx + 1; i < k; i++) {
        if (__gcd(lcm, p[i]) == lcm)
            count(i, lcm * p[i], cnt + 1);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> p[i];
    for (int i = 0; i < k; i++) count(i, p[i], 1);
    cout << res;
}