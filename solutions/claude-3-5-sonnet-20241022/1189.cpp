#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<long long> diff(n);
    for(int i = 0; i < n; i++) {
        diff[i] = a[i] - b[i];
    }
    
    long long steps = 0;
    long long curr = 0;
    
    for(int i = 0; i < n; i++) {
        curr += diff[i];
        steps += abs(curr);
    }
    
    cout << steps;
    return 0;
}