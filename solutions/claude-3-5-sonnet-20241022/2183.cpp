#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        if(x[i] > sum + 1) break;
        sum += x[i];
    }
    cout << sum + 1;
    return 0;
}