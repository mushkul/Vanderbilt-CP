#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int arr[1000002];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    arr[0] = 1, arr[1] = 0;
    for (int i=2; i<=n; i++){
        arr[i] = 1LL * (i - 1) * (arr[i-1] + arr[i-2]) % MOD;
    }
        
    cout << arr[n];

    return 0;
}