#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

int n;
int arr[MAXN];
int bit[MAXN];

void update(int idx, int val) {
    while (idx <= n) {
        bit[idx] = (bit[idx] + val) % MOD;
        idx += idx & -idx;
    }
}

int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum = (sum + bit[idx]) % MOD;
        idx -= idx & -idx;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    vector<int> compressed(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        compressed[i] = arr[i];
    }
    
    sort(compressed.begin(), compressed.end());
    compressed.erase(unique(compressed.begin(), compressed.end()), compressed.end());
    
    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(compressed.begin(), compressed.end(), arr[i]) - compressed.begin() + 1;
    }
    
    int result = 0;
    for (int i = 0; i < n; i++) {
        int prev_sum = query(arr[i] - 1);
        result = (result + prev_sum + 1) % MOD;
        update(arr[i], prev_sum + 1);
    }
    
    cout << result << "\n";
    return 0;
}