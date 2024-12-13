#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll maxXor = 0;
    for (int i = 0; i < n; i++) {
        ll currXor = 0;
        for (int j = i; j < n; j++) {
            currXor ^= arr[j];
            maxXor = max(maxXor, currXor);
        }
    }
    
    cout << maxXor << endl;
    return 0;
}