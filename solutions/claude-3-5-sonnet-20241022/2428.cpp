#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    ll ans = 0;
    map<int, int> freq;
    int distinct = 0;
    int left = 0;
    
    for(int right = 0; right < n; right++) {
        freq[a[right]]++;
        if(freq[a[right]] == 1) {
            distinct++;
        }
        
        while(distinct > k) {
            freq[a[left]]--;
            if(freq[a[left]] == 0) {
                distinct--;
            }
            left++;
        }
        
        ans += right - left + 1;
    }
    
    cout << ans;
    return 0;
}