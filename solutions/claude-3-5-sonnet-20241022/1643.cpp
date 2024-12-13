#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll maxSum = arr[0];
    ll currSum = arr[0];
    
    for(int i = 1; i < n; i++) {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    
    cout << maxSum;
    return 0;
}