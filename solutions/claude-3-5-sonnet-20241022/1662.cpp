#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<ll> prefix(n + 1, 0);
    map<ll, ll> count;
    count[0] = 1;
    ll result = 0;
    
    for(int i = 0; i < n; i++) {
        prefix[i + 1] = (prefix[i] + nums[i]) % n;
        if(prefix[i + 1] < 0) prefix[i + 1] += n;
        result += count[prefix[i + 1]];
        count[prefix[i + 1]]++;
    }
    
    cout << result << endl;
    return 0;
}