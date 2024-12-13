#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll ans = 0;
    unordered_map<int, int> freq;
    int left = 0;
    
    for (int right = 0; right < n; right++) {
        freq[arr[right]]++;
        
        while (freq.size() > k) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0) {
                freq.erase(arr[left]);
            }
            left++;
        }
        
        ans += right - left + 1;
    }
    
    cout << ans << endl;
    return 0;
}