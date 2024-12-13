#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_map<ll, int> prefixSumCount;
    ll prefixSum = 0;
    ll count = 0;
    
    prefixSumCount[0] = 1;
    
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        
        if (prefixSumCount.find(prefixSum - x) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - x];
        }
        
        prefixSumCount[prefixSum]++;
    }
    
    cout << count << endl;
    
    return 0;
}