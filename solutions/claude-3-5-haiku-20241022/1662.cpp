#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    vector<ll> prefix(n + 1, 0);
    unordered_map<ll, ll> remainders;
    remainders[0] = 1;
    
    ll current_sum = 0;
    ll count = 0;
    
    for (int i = 0; i < n; i++) {
        current_sum += arr[i];
        
        ll remainder = ((current_sum % n) + n) % n;
        
        count += remainders[remainder];
        
        remainders[remainder]++;
    }
    
    cout << count << endl;
    
    return 0;
}