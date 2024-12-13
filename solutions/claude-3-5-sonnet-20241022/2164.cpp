#include <bits/stdc++.h>
using namespace std;

long long solve(long long n, long long k) {
    if(n == 1) return 1;
    if(k <= (n+1)/2) {
        return 2*k;
    }
    long long temp = solve(n/2, k-(n+1)/2);
    if(n%2 == 1) {
        return 2*temp - 1;
    }
    return 2*temp - 3;
}

int main() {
    int q;
    cin >> q;
    while(q--) {
        long long n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}