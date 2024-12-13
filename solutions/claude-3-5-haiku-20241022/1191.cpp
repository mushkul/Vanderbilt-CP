#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(2*n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i+n] = arr[i];
    }
    
    int ans = INT_MAX;
    for(int start = 0; start < n; start++) {
        ll sum = 0;
        int subarrays = 0;
        
        for(int i = start; i < start + n; i++) {
            if(sum + arr[i] > k) {
                subarrays++;
                sum = arr[i];
            } else {
                sum += arr[i];
            }
        }
        
        ans = min(ans, subarrays + 1);
    }
    
    cout << ans << endl;
    return 0;
}