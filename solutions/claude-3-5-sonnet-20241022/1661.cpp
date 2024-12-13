#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, x;
    cin >> n >> x;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<long long, long long> sums;
    long long sum = 0;
    long long result = 0;
    
    sums[0] = 1;
    
    for(int i = 0; i < n; i++) {
        sum += a[i];
        result += sums[sum - x];
        sums[sum]++;
    }
    
    cout << result;
    return 0;
}